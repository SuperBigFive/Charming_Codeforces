#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
int add(int a, int b) { a += b; return a < P ? a : a - P; }
int sub(int a, int b) { a -= b; return a < 0 ? a + P : a; }
int mul(int a, int b) { return 1ll * a * b % P; }
int qpm(int a, int b) {
    int r = 1;
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}
int inv(int x) { return qpm(x, P - 2); }

typedef vector<int> vec;
typedef vector<vec> mat;

mat mul(mat a, mat b) {
    int n = a.size(), m = b[0].size(), c = a[0].size();
    mat r(n, vec(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < c; ++k)
                r[i][j] = add(r[i][j], mul(a[i][k], b[k][j]));
    return r;
}

void print(mat m) {
    for (int i = 0; i < m.size(); ++i)
        for (int j = 0; j < m[i].size(); ++j)
            printf("%d%c", m[i][j], " \n"[j + 1 == m[i].size()]);
    printf("\n");
}

mat van(vec x) {
    const int n = x.size();
    mat m(n, x);
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < n; ++j)
            m[i][j] = mul(m[i - 1][j], x[j]);
    return m;
}

namespace sol1 {

typedef vec vi;

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

}

using NTT1::pmul;

mat ivan(vec x) {
    const int n = x.size();
    mat al(n, vec(n + 1, 0)), ar(n, vec(n + 1, 0));
    for (int i = 0; i < n; ++i)
        al[i][0] = ar[i][0] = 1;
    for (int i = 1; i <= n - 1; ++i)
        for (int j = 1; j <= i; ++j)
            al[i][j] = add(al[i - 1][j], mul(x[i - 1], al[i - 1][j - 1])),
            ar[i][j] = add(ar[i - 1][j], mul(x[n - i], ar[i - 1][j - 1]));
    mat a(n);
    for (int i = 1; i <= n; ++i)
        a[i - 1] = pmul(al[i - 1], ar[n - i]);
    vec b = x;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (j != i) b[i] = mul(b[i], sub(x[j], x[i]));
    for (int i = 0; i < n; ++i)
        b[i] = inv(b[i]);
    mat r(n, vec(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            r[i][j] = (j & 1 ? sub : add)(0, mul(b[i], a[i][n - j - 1]));
    return r;
}

}

namespace sol2 {

mat ivan(vec x) {
    const int n = x.size();
    vec c(n + 1, 0); c[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j >= 1; --j)
            c[j] = add(c[j], mul(x[i - 1], c[j - 1]));
    mat a(n, c);
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = sub(a[i][j], mul(x[i], a[i][j - 1]));
    vec b = x;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (j != i) b[i] = mul(b[i], sub(x[j], x[i]));
    for (int i = 0; i < n; ++i)
        b[i] = inv(b[i]);
    mat r(n, vec(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            r[i][j] = (j & 1 ? sub : add)(0, mul(b[i], a[i][n - j - 1]));
    return r;
}

}

mt19937_64 mt(time(0));
uniform_int_distribution<int> uid(1, P - 1);
vec get_x(int n) {
    set<int> s;
    vec x(n);
    for (int i = 0; i < n; ++i) {
        do x[i] = uid(mt);
        while (!s.insert(x[i]).second);
    }
    return x;
}

int main(void) {
    sol1::NTT1::init();
    int n;
    scanf("%d", &n);
    vec x = get_x(n);
    clock_t tt = clock();
    mat a = van(x), b = sol2::ivan(x);//, c = mul(a, b);
    int sum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            sum ^= b[i][j];//, assert(c[i][j] == (i == j));
    printf("%d\n", sum);
    fprintf(stderr, "%d\n", clock() - tt);
    return 0;
}