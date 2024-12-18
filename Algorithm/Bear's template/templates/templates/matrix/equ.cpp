#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
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

void print(mat m) {
    for (auto v : m) {
        for (int i : v)
            printf("%d ", i);
        printf("\n");
    }
}

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

mt19937_64 mt(time(0));
uniform_int_distribution<int> uid(0, P - 1);

int rnd() { return uid(mt); }

int main(void) {
    int n;
    while (~scanf("%d", &n)) {
        mat a(n, vec(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] = rnd();
        vec b(n, 0);
        for (int i = 0; i < n; ++i)
            b[i] = rnd();
        vec r = solve(a, b);
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int j = 0; j < n; ++j)
                s = add(s, mul(a[i][j], r[j]));
            assert(s == b[i]);
        }
    }
    return 0;
}