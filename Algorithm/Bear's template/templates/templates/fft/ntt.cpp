#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18;
const int P = 1000000007;

typedef vector<int> vi;

inline int add(int a, int b) { int r = a + b; return r < P ? r : r - P; }
inline int sub(int a, int b) { int r = a - b; return r < 0 ? r + P : r; }
inline int mul(int a, int b) { return 1ll * a * b % P; }
inline int qpm(int a, int b) {
    int r = 1;
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}
inline int inv(int x) { return qpm(x, P - 2); }

int msqrt(int x) {
    if (!x) return 0;
    if (qpm(x, (P - 1) / 2) != 1) return -1;
    if (P % 4 == 3) return qpm(x, (P + 1) / 4);
    int z = 2; while (qpm(z, (P - 1) / 2) == 1) ++z;
    const int s = __builtin_ctz(P - 1), q = (P - 1) >> s;
    int r = qpm(x, (q + 1) / 2), t = qpm(x, q);
    z = qpm(z, q);
    for (int i = 1; i < s; ++i) {
        int y = mul(z, z);
        if (qpm(t, 1 << (s - i - 1)) != 1)
            t = mul(t, y), r = mul(r, z);
        z = y;
    }
    return r;
}

int invs[N], fac[N], ifac[N];
int binom(int n, int k) { return mul(fac[n], mul(ifac[n - k], ifac[k])); }
void ginv() {
    invs[1] = 1; fac[0] = ifac[0] = 1;
    for (int i = 2; i != N; ++i) invs[i] = mul(invs[P % i], (P - P / i));
    for (int i = 1; i != N; ++i) fac[i] = mul(fac[i - 1], i);
    for (int i = 1; i != N; ++i) ifac[i] = mul(ifac[i - 1], invs[i]);
}

vi padd(const vi& p1, const vi& p2) {
    int n3 = max(p1.size(), p2.size());
    vi pr = p1; pr.resize(n3, 0);
    for (int i = 0; i != p2.size(); ++i) pr[i] = add(pr[i], p2[i]);
    return pr;
}

vi psub(const vi& p1, const vi& p2) {
    int n3 = max(p1.size(), p2.size());
    vi pr = p1; pr.resize(n3, 0);
    for (int i = 0; i != p2.size(); ++i) pr[i] = sub(pr[i], p2[i]);
    return pr;
}

vi pmul(const vi& p1, int k) {
    int n1 = p1.size(); vi p2(n1);
    for (int i = 0; i != n1; ++i) p2[i] = mul(k, p1[i]);
    return p2;
}

vi egf(const vi& g) {
    vi r(g.size());
    for (int i = 0; i != g.size(); ++i)
        r[i] = mul(g[i], ifac[i]);
    return r;
}

vi iegf(const vi& g) {
    vi r(g.size());
    for (int i = 0; i != g.size(); ++i)
        r[i] = mul(g[i], fac[i]);
    return r;
}

vi deriv(const vi& p1) {
    int n1 = p1.size();
    vi p2(n1 - 1);
    for (int i = 1; i != n1; ++i) p2[i - 1] = mul(i, p1[i]);
    return p2;
}

vi integ(const vi& p1) {
    int n1 = p1.size();
    vi p2(n1 + 1, 0);
    for (int i = 0; i != n1; ++i) p2[i + 1] = mul(p1[i], invs[i + 1]);
    return p2;
}


namespace NTT1 {

using ::mul;
using ::inv;

const int W = 18, S = 1 << W, g = 3;
int w[S + 1], rev[S << 1], *r[W + 1];
void init() {
    for (int s = 0; s <= W&&(r[s]=rev+(1<<s),1); ++s)
        for (int i = 0; i != (1 << s); ++i)
            r[s][i] = (r[s][i >> 1] >> 1) | ((i & 1) << (s - 1));
    w[0] = 1; w[1] = qpm(g, (P - 1) / S);
    for (int i = 2; i <= S; ++i) w[i] = mul(w[i - 1], w[1]);
}

int m, s, im;
int init(int n) {
    for (s = 0, m = 1; m < n; m <<= 1, ++s);
    im = inv(m); return m;
}

void ntt(int* p, const int t) {
    for (int i = 0; i != m; ++i) if (i < r[s][i]) swap(p[i], p[r[s][i]]);
    for (int i = 1, z = 0; i != m; i <<= 1, z++)
        for (int j = 0; j != m; j += (i << 1))
            for (int k = 0, u, v; k != i; k++)
                u = p[j+k], v = mul(w[(t?(i<<1)-k:k)<<W-z-1], p[i+j+k]),
                p[j + k] = add(u, v), p[i + j + k] = sub(u, v);
    if (t) for (int i = 0; i != m; ++i) p[i] = mul(p[i], im);
}

int px[S], py[S];
vi pmul(const vi& p1, const vi& p2, int n = 0) {
    int n1 = p1.size(), n2 = p2.size(), n3 = n1 + n2 - 1;
    init(n3);
    copy_n(p1.begin(), n1, px); fill(px + n1, px + m, 0);
    copy_n(p2.begin(), n2, py); fill(py + n2, py + m, 0);
    ntt(px, 0); ntt(py, 0);
    for (int i = 0; i != m; ++i) px[i] = mul(px[i], py[i]);
    ntt(px, 1); vi p3(n3); copy_n(px, n3, p3.begin());
    if (n && n3 > n) p3.resize(n); return p3;
}

vi pinv(const vi& p1) {
    int n1 = p1.size(), n2 = (n1 + 1) >> 1;
    if (n1 == 1) return { inv(p1[0]) };
    else {
        vi p2 = pinv(vi(p1.begin(), p1.begin() + n2));
        init(n1 << 1);
        copy_n(p1.begin(), n1, px); fill(px + n1, px + m, 0);
        copy_n(p2.begin(), n2, py); fill(py + n2, py + m, 0);
        ntt(px, 0); ntt(py, 0);
        for (int i = 0; i != m; ++i)
            px[i] = mul(sub(2, mul(px[i], py[i])), py[i]);
        ntt(px, 1); vi p3(n1); copy_n(px, n1, p3.begin());
        return p3;
    }
}

}

using NTT1::init;
using NTT1::pmul;
using NTT1::pinv;

namespace NTT2 {

    typedef array<int, 3> mint;
    const int M[3] = { 167772161, 469762049, 998244353 }, g = 3;

    template<const int i> inline int add(int a, int b) { int r = a + b; return r < M[i] ? r : r - M[i]; }
    template<const int i> inline int sub(int a, int b) { int r = a - b; return r < 0 ? r + M[i] : r; }
    template<const int i> inline int mul(int a, int b) { return 1ll * a * b % M[i]; }
    template<const int i> inline int qpm(int a, int b, int r = 1) {
        do if (b & 1) r = mul<i>(r, a); while (a = mul<i>(a, a), b >>= 1);
        return r;
    }

    inline mint mul(mint a, mint b) { return { mul<0>(a[0], b[0]), mul<1>(a[1], b[1]), mul<2>(a[2], b[2]) }; }

    inline int crt(const mint& x){
        static const int o0 = qpm<1>(M[0], M[1]-2);
        static const int o1 = qpm<2>(1ll * M[0] * M[1] % M[2],M[2]-2);
        long long a = 1ll * (x[1] - x[0] + M[1]) * o0 % M[1] * M[0] + x[0];
        return (1ll * (x[2] - a % M[2] + M[2]) * o1 % M[2] * M[0] % P * M[1] + a) % P;
    }

    const int W = 18, S = 1 << W;
    int rev[S << 1], *r[W + 1];
    mint w[S + 1];
    void init() {
        for (int s = 0; s <= W&&(r[s]=rev+(1<<s),1); ++s)
            for (int i = 0; i != (1 << s); ++i)
                r[s][i] = (r[s][i >> 1] >> 1) | ((i & 1) << (s - 1));
        w[0] = { 1, 1, 1 };
        w[1][0] = qpm<0>(g, (M[0] - 1) / S);
        w[1][1] = qpm<1>(g, (M[1] - 1) / S);
        w[1][2] = qpm<2>(g, (M[2] - 1) / S);
        for (int i = 2; i <= S; ++i) w[i] = mul(w[i - 1], w[1]);
    }

    int m, s; mint im;
    void init(int n) {
        for (s = 0, m = 1; m < n; m <<= 1, ++s);
        im = { qpm<0>(m, M[0]-2), qpm<1>(m, M[1]-2), qpm<2>(m, M[2]-2) };
    }

    void ntt(mint* p, const int t) {
        for (int i = 0; i != m; ++i) if (i < r[s][i]) swap(p[i], p[r[s][i]]);
        for (int i = 1, z = 0; i != m; i <<= 1, z++)
            for (int j = 0; j != m; j += (i << 1))
                for (int k = 0; k != i; k++) {
                    mint u=p[j+k], v=mul(w[(t?(i<<1)-k:k)<<W-z-1], p[i+j+k]);
                    p[j + k] = { add<0>(u[0], v[0]), add<1>(u[1], v[1]), add<2>(u[2], v[2]) };
                    p[i + j + k] = { sub<0>(u[0], v[0]), sub<1>(u[1], v[1]), sub<2>(u[2], v[2]) };
                }
        if (t) for (int i = 0; i != m; ++i) p[i] = mul(p[i], im);
    }

    mint px[S], py[S];
    vi pmul(const vi& p1, const vi& p2, int n = 0) {
        int n1 = p1.size(), n2 = p2.size(), n3 = n1 + n2 - 1;
        init(n3);
        for (int i = 0; i != n1; ++i) px[i] = { p1[i] % M[0], p1[i] % M[1], p1[i] % M[2] };
        for (int i = n1; i != m; ++i) px[i] = { 0, 0, 0 };
        for (int i = 0; i != n2; ++i) py[i] = { p2[i] % M[0], p2[i] % M[1], p2[i] % M[2] };
        for (int i = n2; i != m; ++i) py[i] = { 0, 0, 0 };
        ntt(px, 0); ntt(py, 0);
        for (int i = 0; i != m; ++i) px[i] = mul(px[i], py[i]);
        ntt(px, 1);
        vi p3(n3);
        for (int i = 0; i != n3; ++i) p3[i] = crt(px[i]);
        if (n && n3 > n) p3.resize(n); return p3;
    }

    vi pinv(const vi& p1) {
        int n1 = p1.size(), n2 = (n1 + 1) >> 1;
        if (n1 == 1) return { ::inv(p1[0]) };
        vi p2 = pinv(vi(p1.begin(), p1.begin() + n2));
        return pmul(psub({2}, pmul(p1, p2)), p2, n1);
    }
}

// using NTT2::init;
// using NTT2::pmul;
// using NTT2::pinv;

int main(void) {
    return 0;
}