#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P = 1000000007;
int add(int a, int b) { a += b; return a < P ? a : a - P; }
int sub(int a, int b) { a -= b; return a < 0 ? a + P : a; }
int mul(long long a, long long b) { return a * b % P; }
int qpm(int a, int b, int r = 1) {
    do if(b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}
int inv(int x) { return qpm(x, P - 2); }

int i2 = inv(2), i6 = inv(6);
int s1(int x) { return mul(mul(x, x + 1), i2); }
int s2(int x) { return mul(mul(x, x + 1), mul(2 * x + 1, i6)); }

typedef pair<int, int> pii;

namespace sieve {

int y;

const int N = 1000005, K = 3;

bool ip[N]; ll ps[N], pc;
void eulerian_sieve(int n) {
    fill_n(ip + 1, n, 1); pc = 0; ip[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (ip[i]) ps[++pc] = i;
        for (int j = 1; j <= pc && i * ps[j] <= n; ++j) {
            ip[i * ps[j]] = 0;
            if (i % ps[j] == 0) break;
        }
    }
}


ll n, sq, w[N];
int c, g[K][N];

inline int id(ll x) { return !x ? 0 : (x <= sq ? c + 1 - x : n / x); }

void cal_g(ll n_) {
    n = n_; sq = sqrt(n_); c = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        ll v = w[++c] = n / l; r = n / v;
        g[0][c] = (v - 1) % P;
        g[1][c] = sub(s1(v % P), 1);
        g[2][c] = sub(s2(v % P), 1);
    }
    eulerian_sieve(2 * sq);
    while (ps[pc] > sq) pc--;
    for (int i = 1; i <= pc; ++i)
        for (int j = 1, p = ps[i]; 1ll * p * p <= w[j]; ++j)
            for (ll q = 1, k = 0; k != K; ++k, q *= p)
                g[k][j] = sub(g[k][j], mul(q % P, sub(g[k][id(w[j] / p)], g[k][id(ps[i - 1])])));
}

pii cal_s(int i, ll x) {
    int p = ps[i];
    if (p > x) return pii(0, 0);
    pii res;
    if (1ll * p * p > x) {
        int s[3] = {
            sub(g[0][id(x)], g[0][id(ps[i - 1])]),
            sub(g[1][id(x)], g[1][id(ps[i - 1])]),
            sub(g[2][id(x)], g[2][id(ps[i - 1])])
        };
        res.first = sub(mul(s[1], y), s[0]);
        res.second = sub(add(mul(mul(y, y), s[2]), s[0]), mul(2 * y, s[1]));
    }
    else {
        ll q = p;
        res = cal_s(i + 1, x);
        for (int e = 1; q <= x; ++e, q *= p) {
            int f1 = sub(mul(y, q % P), (q / p) % P);
            int f2 = mul(f1, f1);
            pii res2 = cal_s(i + 1, x / q);
            res.first = add(res.first, mul(f1, add(1, res2.first)));
            res.second = add(res.second, mul(f2, add(1, res2.second)));
        }
    }
    return res;
}
    
}