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

int det(mat a) {
    const int n = a.size(); int res = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && !a[i][i]; ++j)
            if (a[j][i]) swap(a[i], a[j]), res = sub(0, res);
        if (!a[i][i]) return 0; else res = mul(res, a[i][i]);
        for (int j = i + 1, t = inv(a[i][i]); j < n; ++j)
            for (int k = i, w = mul(a[j][i], t); k < n; ++k)
                a[j][k] = sub(a[j][k], mul(w, a[i][k]));
    }
    return res;
}