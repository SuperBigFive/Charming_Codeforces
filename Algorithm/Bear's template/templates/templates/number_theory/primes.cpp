#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int N = 1000005;
bool ip[N]; vector<int> ps;
void sieve() {
    fill_n(ip, N, 1); ip[1] = 0;
    for (int i = 2; i < N; ++i) {
        if (ip[i]) ps.push_back(i);
        for (int j : ps) {
            if (i * j >= N) break;
            ip[i * j] = 0;
            if (i % j == 0) break;
        }
    }
}

vector<pii> decomp(ll n) {
    vector<pii> v;
    for (int p : ps) {
        if (1ll * p * p > n) break;
        if (n % p) continue;
        v.emplace_back(p, 0);
        do v.back().second++; while ((n /= p) % p == 0);
    }
    if (n != 1) v.emplace_back(n, 1);
    return v;
}

ll mul(ll a, ll b, ll p) { return (__int128)a * b % p; }
ll qpm(ll a, ll b, ll p) {
    ll r = 1;
    do if (b & 1) r = mul(r, a, p);
    while(a = mul(a, a, p), b >>= 1);
    return r;
}
//  Miller-Rabin primality test(Deterministic)
//  { 2, 7, 61 } for 2^32
//  { 2, 3, 7, 61, 24251 } for 1e16 (except 46856248255981)
//  { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 } for 2^64
bool mr(ll n) {
    if (n % 2 == 0) return n == 2;
    if (n < 128) return (0X816D129A64B4CB6E >> (n / 2)) & 1;
    const int l[7] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
    ll d0 = n - 1; do d0 >>= 1; while(!(d0 & 1));
    for (ll a : l) {
        if (a % n == 0) return true;
        ll d = d0, t = qpm(a, d, n);
        while(d != n - 1 && t != 1 && t != n - 1)
            d <<= 1, t = mul(t, t, n);
        if (t != n - 1 && !(d & 1)) return false;
    }
    return true;
}

ll pr(ll n) {
    ll x = 0, y = 0, t = 1, q = 1, c = rand() % (n - 1) + 1;
    for (int k = 2;; k <<= 1, y = x, q = 1) {
        for (int i = 1; i <= k; ++i) {
            x = (mul(x, x, n) + c) % n;
            q = mul(q, abs(x - y), n);
            if (!(i&127) && (t = __gcd(q, n) > 1))
                break;
        }
        if (t > 1 || (t = __gcd(q, n)) > 1) break;
    }
    return t;
}

void pfd_pr(vector<ll>& ds, ll n) {
    if (mr(n)) return ds.push_back(n);
    ll p = n; while(p >= n) p = pr(n);
    pfd_pr(ds, p); pfd_pr(ds, n / p);
}

struct pf { ll p, c; };
vector<pf> pfd(ll n) {
    vector<ll> v; pfd_pr(v, n);
    sort(v.begin(), v.end());
    vector<pf> res(1, { v[0], 0 });
    for (ll p : v) {
        if (res.back().p != p)
            res.push_back({ p, 1 });
        else res.back().c++;
    }
    return res;
}

int main(void) {

    ll n;
    while (~scanf("%lld", &n)) {
        printf("%s\n", mr(n) ? "Prime" : "Composite");
    }

    return 0;
}