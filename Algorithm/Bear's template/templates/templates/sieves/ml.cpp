#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace ML {

const int N = 3000001, P = 7, M = 2*3*5*7*11*13*17;
bool ip[N]; int ps[N], pi[N];
int phi[P+1][M+1], sz[P+1], pc;
void init() {
    fill_n(ip, N, 1); pc = 0; ip[1] = 0;
    for (int i = 2; i < N; ++i) {
        pi[i] = pi[i - 1];
        if (ip[i]) ps[++pc] = i, pi[i]++;
        for (int j = 1; j <= pc && i * ps[j] < N; ++j) {
            ip[i * ps[j]] = 0;
            if (i % ps[j] == 0) break;
        }
    }  
    iota(phi[0], phi[0] + M + 1, 0);
    for (int i = sz[0] = 1; i <= P; ++i) {
        sz[i] = ps[i] * sz[i - 1];
        for (int j = 1; j <= M; ++j)
            phi[i][j] = phi[i - 1][j] - phi[i - 1][j / ps[i]];
    }
}

int sq(ll x) { return (int)floor(sqrt(x)); }
int cb(ll x) { return (int)floor(cbrt(x)); }

ll legendre_phi(ll x, int a) {
    if (a == 0) return x;
    if (a <= P) return phi[a][x % sz[a]] + (x / sz[a]) * phi[a][sz[a]];
    if (x <= 1ll * ps[a] * ps[a]) return pi[x] - a + 1;
    if (x <= 1ll * ps[a] * ps[a] * ps[a] && x < N) {
        int b = pi[sq(x)];
        ll res = pi[x] - 1ll * (b + a - 2) * (b - a + 1) / 2;
        for (int i = a + 1; i <= b; ++i)
            res += pi[x / ps[i]];
        return res;
    }
    return legendre_phi(x, a - 1) - legendre_phi(x / ps[a], a - 1);
}

ll meissel_pi(ll x) {
    if (x < N) return pi[x];
    int c = pi[cb(x)], b = pi[sq(x)];
    ll res = legendre_phi(x, c) + c - 1;
    for (int i = c + 1; i <= b; ++i)
        res -= meissel_pi(x / ps[i]) - i + 1;
    return res;
}

ll lehmer_pi(ll x) {
    if (x < N) return pi[x];
    int a = pi[sq(sq(x))], b = pi[sq(x)], c = pi[cb(x)];
    ll res = legendre_phi(x, a) + 1ll * (b + a - 2) * (b - a + 1) / 2;
    for (int i = a + 1; i <= b; ++i) {
        ll w = x / ps[i];
        res -= lehmer_pi(w);
        if (i > c) continue;
        for (int j = i, bi = pi[sq(w)]; j <= bi; ++j)
            res -= lehmer_pi(w / ps[j]) - (j - 1);
    }
    return res;
}

}

using namespace ML;
int main(void) {
    init();
    ll x; 
    auto tp = std::chrono::system_clock::now();
    while (~scanf("%lld", &x))
        printf("%lld\n", meissel_pi(x));
    cerr << chrono::duration_cast<chrono::milliseconds>(std::chrono::system_clock::now() - tp).count() << endl;
    return 0;
}