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
                r[i][j] = add(r[i][j], mul(b[i][k], c[k][j]));
    return r;
}
