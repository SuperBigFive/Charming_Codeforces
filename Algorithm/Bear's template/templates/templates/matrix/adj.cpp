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

mat adj0(mat a) {
    int n = a.size();
    mat b(n, vec(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat c = a;
            c.erase(c.begin() + i);
            for (vec& v : c)
                v.erase(v.begin() + j);
            b[j][i] = ((i + j) & 1 ? sub : add)(0, det(c));
        }
    }
    return b;
}

mat adj(mat a) {
    int n = a.size(), d = 1, rk = n, id = -1;
    mat b = a;
    vec t(n); iota(t.begin(), t.end(), 0);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && !a[i][i]; ++j)
            if (a[j][i]) swap(a[i], a[j]), swap(t[i], t[j]), d = sub(0, d);
        if (!a[i][i]) { 
            if (rk-- == n - 2)
                return mat(n, vec(n, 0));
            id = t[i];
        }
        d = mul(d, a[i][i]);
        for (int j = i + 1, t = inv(a[i][i]); j < n; ++j)
            for (int k = i, w = mul(a[j][i], t); k < n; ++k)
                a[j][k] = sub(a[j][k], mul(w, a[i][k]));
    }
    if (rk == n) {
        a = inv(b);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] = mul(a[i][j], d);
        return a;
    }
    a = b;
    a.resize(n - 1);
    for (vec& v : a) v.resize(n - 1);
    a = inv(a);
    vec u(n - 1, 0), v(n - 1, 0);
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1; ++j)
            u[i] = add(u[i], mul(a[i][j], b[j][n - 1])),
            v[j] = add(v[j], mul(a[i][j], b[n - 1][i]));
    mat r(n, vec(n, 0)); r[n - 1][n - 1] = d;
    for (int i = 0; i < n - 1; ++i)
        r[i][n - 1] = mul(sub(0, d), u[i]),
        r[n - 1][i] = mul(sub(0, d), v[i]);
    d = inv(d);
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1; ++j)
            r[i][j] = mul(mul(r[i][n - 1], r[n - 1][j]), d);
            
    swap(r[id], r[n - 1]);
    return r;
}

void print(mat m) {
    for (int i = 0; i < m.size(); ++i)
        for (int j = 0; j < m[i].size(); ++j)
            printf("%d%c", m[i][j], " \n"[j + 1 == m[i].size()]);
}

int main(void) {
    int n; cin >> n;// >> P;
    mat a(n, vec(n));
    for (vec& v : a) for(int& i : v) cin >> i;
    //print(inv(a));
    //printf("%d\n", det(a));
    //assert(adj(a) == adj0(a));
    print(adj(a));
    //puts("");
    //print(adj0(a));
    return 0;    
}