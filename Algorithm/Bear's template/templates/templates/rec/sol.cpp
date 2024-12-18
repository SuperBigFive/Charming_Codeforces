#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int P = 1000000007;
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

typedef vector<int> vi;
vi berlekamp_massey(const vi& a) {
    int p = 0, d_ = a[0]; vi b = { 0 }, c = { 0 }; 
    for (int i = 0; i < a.size(); ++i) {
        int d = a[i], k = (int)c.size() - 1;
        for (int j = 1; j <= k; ++j) d = sub(d, mul(a[i - j], c[j]));
        if (!d) continue;
        if (!k) { c.resize(i + 2); p = i; d_ = a[i]; continue; }
        int m = (int)b.size() - 1, w = mul(d, inv(d_));
        vi b_ = c; c.resize(max((int)c.size(), i - p + m + 1), 0);
        c[i - p] = add(c[i - p], w);
        for (int j = i - p + 1; j <= i - p + m; ++j)
            c[j] = sub(c[j], mul(w, b[j - (i - p)]));
        if (i - p + m + 1 >= b_.size()) b = b_, d_ = d, p = i;
    }
    return c;
}

vi mul(const vi& a, const vi& b) {
    const int n1 = a.size(), n2 = b.size();
    vi c(n1 + n2 - 1, 0);
    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < n2; ++j)
            c[i + j] = add(c[i + j], mul(a[i], b[j]));
    return c;
}

pair<vi, vi> div(const vi& a, const vi& b) {
    const int n1 = a.size(), n2 = b.size();
    if (n1 < n2) return { vi(), a };
    vi r = a, q(n1 - n2 + 1);
    for (int i = n1 - n2; i >= 0; --i) {
        q[i] = mul(r[i + n2 - 1], inv(b.back()));
        for (int j = 0; j < n2; ++j)
            r[i + j] = sub(r[i + j], mul(q[i], b[j]));
    }
    while (!r.empty() && !r.back()) r.pop_back();
    return { q, r };
}

int linear_recursion(ll n, const vi& a, const vi& c) {
    int k = c.size() - 1;
    vi f(k + 1, 0), g = { 0, 1 }, b = { 1 }; f[k] = 1;
    for (int i = 1; i <= k; ++i) f[k - i] = sub(0, c[i]);
    do if (n & 1) b = div(mul(b, g), f).second;
    while (g = div(mul(g, g), f).second, n >>= 1);
    int res = 0;
    for (int i = 0; i <= k - 1; ++i)
        res = add(res, mul(a[i], b[i]));
    return res;
}

int solve(const vi& a, ll n) {
    return linear_recursion(n, a, berlekamp_massey(a));
}

typedef vector<int> vec;
typedef vector<vec> mat;

vec solve(mat a, vec b) {
    const int n = a.size();
    for (int i = 0; i < n; ++i)
        a[i].push_back(b[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; !a[i][i] && j < n; ++j)
            if (a[j][i]) swap(a[i], a[j]);
        if (!a[i][i]) return {};
        for (int w = inv(a[i][i]), j = i; j <= n; ++j)
            a[i][j] = mul(a[i][j], w);
        for (int k = 0; k < n; ++k)
            if (k != i)
                for (int j = n; j >= i; --j)
                    a[k][j] = sub(a[k][j], mul(a[k][i], a[i][j]));
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            assert(a[i][j] == (i == j));
    vec r(n);
    for (int i = 0; i < n; ++i)
        r[i] = a[i][n];
    return r;
}

vi gen(int k, int w = 2) {
    int n = w * k + 1, ik = inv(k);
    mat a(n, vec(n, 0));
    vec b(n, 0);
    a[0][0] = 1; b[0] = 0;
    for (int i = 1; i < n; ++i) {
        a[i][i] = 1;
        for (int j = 1; j <= k; ++j) {
            int t = abs(i - j);
            a[i][t] = sub(a[i][t], ik);
        }
        b[i] = 1;
    }
    return solve(a, b);
}

int main(void) {
    int k; ll d;
    scanf("%lld %d", &d, &k);
    vi a = gen(k, 4);
    printf("%d\n", solve(a, d));
    
    return 0;
}