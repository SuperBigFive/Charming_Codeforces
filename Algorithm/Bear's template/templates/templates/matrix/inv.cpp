#include <bits/stdc++.h>
using namespace std;

int P;
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

mat inv(mat a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        a[i].resize(2 * n, 0);
        a[i][n + i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && !a[i][i]; ++j)
            if (a[j][i]) swap(a[i], a[j]);
        if (!a[i][i]) return {};
        for (int j = i, t = inv(a[i][i]); j < 2 * n; ++j)
            a[i][j] = mul(a[i][j], t);
        for (int j = 0; j < n; ++j) if(j != i)
            for (int k = i, t = a[j][i]; k < 2 * n; ++k)
                a[j][k] = sub(a[j][k], mul(t, a[i][k]));
    }
    for (int i = 0; i < n; ++i) {
        copy_n(a[i].begin() + n, n, a[i].begin());
        a[i].resize(n);
    }
    return a;
}

int main(void) {
    int n; cin >> n >> P;
    mat a(n, vec(n));
    for (vec& v : a) {
        for (int& i : v)
            cin >> i;
    }
    a = inv(a);
    for (const vec& v : a) {
        for (int i : v)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}