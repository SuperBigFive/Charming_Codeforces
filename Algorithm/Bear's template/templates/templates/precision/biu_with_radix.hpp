#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace NTT {

const int P = 1004535809, g = 3;

inline int add(int a, int b) { int r = a + b; return r < P ? r : r - P; }
inline int sub(int a, int b) { int r = a - b; return r < 0 ? r + P : r; }
inline int mul(ll a, ll b) { ll r = a * b; return r % P; }
inline int inv(int a) { return a == 1 ? a : mul(inv(P % a), P - P / a); }
inline int qpm(int a, int b) {
    int r = 1;
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}

const int W = 20, S = 1 << W;
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

void ntt(int* p, int t) {
    for (int i = 0; i != m; ++i) if (i < r[s][i]) swap(p[i], p[r[s][i]]);
    for (int i = 1, z = 0; i != m; i <<= 1, z++)
        for (int j = 0; j != m; j += (i << 1))
            for (int k = 0, u, v; k != i; k++)
                u = p[j+k], v = mul(w[(t?(i<<1)-k:k)<<W-z-1], p[i+j+k]),
                p[j + k] = add(u, v), p[i + j + k] = sub(u, v);
    if (t) for (int i = 0; i != m; ++i) p[i] = mul(p[i], im);
}

int p1[S], p2[S], p3[S];
vector<int> conv(const vector<int>& b1, const vector<int>& b2) {
    int n1 = b1.size(), n2 = b2.size(), n3 = n1 + n2;
    if (n3 <= 100) {
        fill_n(p3, n3, 0);
        for (int i = 0; i != n1; ++i)
            for (int j = 0; j != n2; ++j)
                p3[i + j] += b1[i] * b2[j];
    }
    else {
        init(n3);
        copy_n(b1.begin(), n1, p1); fill(p1 + n1, p1 + m, 0);
        copy_n(b2.begin(), n2, p2); fill(p2 + n2, p2 + m, 0);
        ntt(p1, 0); ntt(p2, 0);
        for (int i = 0; i != m; ++i) p3[i] = mul(p1[i], p2[i]);
        ntt(p3, 1);
    }
    return vector<int>(p3, p3 + n3 - 1);
}
}

const char* rch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
template<size_t rad = 10>
struct biu : vector<int> {
    biu(ll x = 0) {  while (x) push_back(x % rad), x /= rad; }

    void trim() { while (!empty() && !back()) pop_back(); }

    friend int cmp(const biu& b1, const biu& b2) {
        int n1 = b1.size(), n2 = b2.size();
        if (n1 != n2) return n1 < n2 ? -1 : 1;
        for (int i = n1 - 1; i >= 0; --i)
            if (b1[i] != b2[i]) return b1[i] < b2[i] ? -1 : 1;
        return 0;
    }

    friend biu operator+(const biu& b1, const biu& b2) {
        int n1 = b1.size(), n2 = b2.size();
        biu b; b.assign(max(n1, n2) + 1, 0);
        for (int i = 0; i != max(n1, n2); ++i) {
            b[i] += (i < n1 ? b1[i] : 0) + (i < n2 ? b2[i] : 0);
            b[i + 1] += b[i] / rad, b[i] %= rad;
        }
        return b.trim(), b;
    }

    friend biu operator-(const biu& b1, const biu& b2) {
        int n2 = b2.size(), j; biu b = b1;
        for (int i = n2 - 1; i >= 0; --i) {
            if (b[i] < b2[i]) {
                for (j = i + 1; !b[j]; ++j) b[j] = rad - 1;
                b[j]--, b[i] += rad;
            }
            b[i] -= b2[i];
        }
        return b.trim(), b;
    }

    friend ll to_llong(const biu& b) {
        ll r = 0, w = 1;
        for (int i : b) r += i * w, w *= 10;
        return r;
    }

    // NTT
    friend biu operator*(const biu& b1, const biu& b2) {
        if (b1.empty() || b2.empty()) return {};
        vector<int> v = NTT::conv(b1, b2);
        int n3 = v.size(); biu b; b.assign(n3 + 1, 0);
        for (int i=0;i!=n3;++i)b[i]+=v[i],b[i + 1]+=b[i]/rad,b[i]%=rad;
        return b.trim(), b;
    }

    friend pair<biu, biu> operator/(const biu& b1, const biu& b2) {
        int r = cmp(b1, b2);
        if (r == -1) return { 0, b1 };
        else if (r == 0) return { 1, 0 };
        int n1 = b1.size(), n2 = b2.size(), s;
        biu y; y.assign(1, 0); y.back()=rad*rad/(b2.back()*rad+(n2>1?b2.end()[-2]:0));
        for (s = 1; s / 4 <= n1; s <<= 1) {
            biu w(b2); int t = s + 1;
            if (n2 < t) w.insert(w.begin(), t - n2, 0);
            else w.erase(w.begin(), w.begin() + n2 - t);
            w = w * y; w.erase(w.begin(), w.begin() + t - 1);
            biu z; z.assign(s + 1, 0); z.back() = 2;
            y = y * (z - w);
        }
        biu b = y * b1; b.erase(b.begin(), b.begin() + s - 1 + n2);
        biu w = b * b2, w2 = w + b2;
        while (cmp(w2, b1) <= 0) b = b + 1, w = move(w2), w2 = w + b2;
        return { b, b1 - w };
    }

};

template<size_t rad>
string to_string(const biu<rad>& b) {
    int n = b.size(); if (!n) return "0";
    string s; for (int i = n - 1; i >= 0; --i) s += rch[b[i]];
    return s;
}

template<size_t rad = 10>
biu<rad> from_string(const string& s) {
    biu<rad> b; for (char ch : s) b.push_back(strchr(rch, ch) - rch);
    reverse(b.begin(), b.end()); return b;
}

template<size_t rad, size_t k, size_t r2 = 1ULL << k>
biu<r2> convto2k(const biu<rad>& b) {
    static_assert(r2 > rad);
    vector<biu<r2>> w(1, biu<r2>(rad));
    for (int i = 1; (1 << i) < b.size(); ++i) w.push_back(w.back() * w.back());
    const int e = w.size(); vector<biu<r2>> v(1 << e, 0);
    for (int i = 0; i != b.size(); ++i) v[i] = biu<r2>(b[i]);
    for (int i = 1; i <= e; ++i)
        for (int j = 0; (j << i) < (1 << e); j++)
            v[j] = v[2 * j] + v[2 * j + 1] * w[i - 1];
    return v[0];
}

template<size_t rad, size_t k, size_t r2 = 1ULL << k>
biu<rad> convfrom2k(const biu<r2>& b) {
    static_assert(r2 > rad);
    vector<biu<r2>> w(1, biu<r2>(rad));
    for (int i = 1; cmp(w.back(), b) == -1; ++i) w.push_back(w.back() * w.back());
    w.pop_back();
    const int e = w.size(); vector<biu<r2>> v(1 << e);
    v[0] = b;
    for (int i = e; i >= 1; --i)
        for (int j = (1 << (e - i)) - 1; j >= 0; j--) 
            tie(v[2 * j + 1], v[2 * j]) = v[j] / w[i - 1];
    biu<rad> res;
    for (int i = 0; i != 1 << e; ++i) res.push_back(v[i].empty() ? 0 : v[i][0]);
    res.trim();
    return res;
}

template<size_t k, size_t r2 = 1ULL << k>
int ctz(biu<r2>& a) {
    int c = 0; while (!a[c]) ++c;
    return c * k + __builtin_ctz(a[c]);
}

template<size_t k, size_t r2 = 1ULL << k>
void rshift2k(biu<r2>& a, int d) {
    if (!d) return;
    int q = d / k, r = d % k, m = r2 - 1, s = a.size();;
    for (int i = 0; i != s; ++i)
        a[i] = (i + q < s ? a[i + q] : 0);
    for (int i = 0; i != s; ++i)
        a[i] = (a[i] >> r) | (i + 1 == s ? 0 : (a[i + 1] << (k - r)) & m);
    a.trim();
}

template<size_t k, size_t r2 = 1ULL << k>
void lshift2k(biu<r2>& a, int d) {
    if (!d) return;
    int q = d / k, r = d % k, m = r2 - 1;
    int s = a.size() + q + (r != 0); a.resize(s);
    for (int i = s - 1; i >= 0; --i)
        a[i] = (i - q < 0 ? 0 : a[i - q]);
    for (int i = s - 1; i >= 0; --i)
        a[i] = ((a[i] << r) & m) | (i == 0 ? 0 : a[i - 1] >> (k - r));
    a.trim();
}

template<size_t rad, size_t k, size_t r2 = 1ULL << k>
biu<rad> gcd(const biu<rad>& u, const biu<rad>& v) {
    biu<r2> a(convto2k<rad, k>(u)), b(convto2k<rad, k>(v));
    int c = 0;
    while (!a.empty() && !b.empty()) {
        int ca = ctz<k>(a); 
        int cb = ctz<k>(b);
        rshift2k<k>(a, ca);
        rshift2k<k>(b, cb);
        c += min(ca, cb);
        if (cmp(a, b) == -1) swap(a, b);
        a = a - b;      
    }
    biu<r2> res = a.empty() ? b : a;
    lshift2k<k>(res, c); 
    return convfrom2k<rad, k>(res);
}
