#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll P = 1000000007;
int add(int a, int b) { a += b; return a < P ? a : a - P; }
int sub(int a, int b) { a -= b; return a < 0 ? a + P : a; }
int mul(long long a, long long b) { return a * b % P; }
int qpm(int a, int b, int r = 1) {
    do if(b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}
int inv(int x) { return qpm(x, P - 2); }

const int N = 100001;
int mu[N], ph[N];
vector<int> ds[N];

void get_phi(int n) {
    for (int i = 1; i <= n; ++i) {
        ph[i] = i;
        for (int j = 2 * i; j <= n; j += i)
            ph[j] -= ph[i];
    }
}

void get_mu(int n) {
    mu[1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 2 * i; j <= n; j += i)
            mu[j] -= mu[i];
}

bool is_prime[N];
vector<int> primes;
int pe[N], pp[N];
int f[N];
int divisors(int p, int e, int q) { return e + 1; }
int moebiusmu(int p, int e, int q) { return e == 1 ? -1 : e == 0; }
int eulerphi(int p, int e, int q) { return (e==0?1:(q/p)*(p-1)); }
const int k = 2;
int get_f(int p, int e, int q) { return e == 0 ? 1 : k * q - q / p; }
void euler_sieve(int n) {
    fill_n(is_prime + 1, n, true);
   	is_prime[1] = 0;
    pe[1] = 0; pp[1] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            pe[i] = 1;
            pp[i] = i;
            f[i] = get_f(i, 1, i);
        }
        for (int p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = 0;
            if (i % p != 0) {
            	pe[i * p] = 1;
                pp[i * p] = p;
                f[i * p] = f[i] * f[p];
            }
            else {
                pe[i * p] = pe[i] + 1;
                pp[i * p] = pp[i] * p;
                f[i * p] = get_f(p, pe[i * p], pp[i * p]) * f[i / pp[i]];
                break;
            }
        }
    }
}

int count(int x) {
    int res = 0;
    for (int l = 1, r; l <= x; l = r + 1) {
        r = x / (x / l);
        res++;
    }
    return res;
}

namespace sieve {

const int N = 1000005, K = 1, a[K] = { - 1 };

int sk(int k, int n) {
    const int i2 = inv(2), i6 = inv(6);
    switch(k) {
        case 0: return n;
        case 1: return mul(mul(n, n + 1), i2);
        case 2: return mul(mul(n, n + 1), mul(2 * n + 1, i6));
    }
    return 114514;
}

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


ll n, sq;		//	sq为sqrt(n)，r为小于等于sq的质数个数，即\pi(\sqrt n)
ll w[N]; int c;			//	w[i]为第i大的n/x。w[1]=n, w[c]=1。
int id1[N], id2[N];		//	如果x>sq，则g_k(i,n)其在w中的位置为id1[x],否则为id2[n/x]
int t[K][N], sf[N], g[K][N];	//	每一轮直接在g[K][N]上递推

inline int& id(ll x) { return x <= sq ? id1[x] : id2[n / x]; }

void init(ll n_) {
    n = n_; sq = sqrt(n_); c = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        ll v = w[++c] = n / l; r = n / v; id(v) = c;
        for (int k = 0; k != K; ++k)
            g[k][c] = sub(sk(k, v % P), 1);
    }

    eulerian_sieve(sq);
    for (int i = 1; i <= pc; ++i) {
        sf[i] = 0;
        for (int k = 0, q = 1; k != K; ++k, q = mul(q, ps[i])) {
            t[k][i] = add(t[k][i - 1], q);
            sf[i] = add(sf[i], mul(a[k], t[k][i]));
        }
    }
    for (int i = 1; i <= pc; ++i)
        for (int j = 1, p = ps[i]; 1ll * p * p <= w[j]; ++j)
            for (int k = 0, q = 1; k != K; ++k, q = mul(q, ps[i]))
                g[k][j] = sub(g[k][j], mul(q, sub(g[k][id(w[j] / p)], t[k][i - 1])));
}

int cal_f(int p, int e, ll q) { return p ^ e; }

int cal_s(int i, ll x) {
    int p = ps[i + 1], res = 0;
    if (p > x) return 0;
    if (1ll * p * p > x)
        for (int k = 0; k != K; ++k)
            res = add(res, mul(a[k], sub(g[k][id(x)], t[k][i])));
    else {
        ll q = p; res = cal_s(i + 1, x);
        for (int e = 1; q <= x; ++e, q *= p) 
            res = add(res, mul(cal_f(p, e, q), add(1, cal_s(i + 1, x / q))));
    }
    return res;
}
    
}

vector<int> fmul(const vector<int>& f, const vector<int>& g) {
    int n = f.size() - 1;
    vector<int> h(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        for (int d : ds[i])
            h[i] = add(h[i], mul(f[d], g[i / d]));
    return h;
}

vector<int> finv(const vector<int>& f) {
    int n = f.size() - 1;
    vector<int> g(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        g[i] = (i == 1);
        for (int d : ds[i]) {
            if (d == i) continue;
            g[i] = g[i] - g[d] * f[i / d];
        }
        g[i] = g[i] / inv(f[1]);
    }
    return g;
}

int main(void) {
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            ds[j].push_back(i);

    const int n = 20;
    
    euler_sieve(n + 5);
    vector<int> ff(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        ff[i] = i;
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ff[i], " \n"[i == n]);
    vector<int> gg = finv(ff);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", gg[i], " \n"[i == n]);
    
    return 0;
}