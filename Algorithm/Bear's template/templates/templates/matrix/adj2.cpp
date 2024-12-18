#include <bits/stdc++.h>
using namespace std;

const int P = 5;
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

uniform_int_distribution<int> uid(0, P - 1);
mt19937_64 mt(time(0));

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> pii;

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

mat adj_bf(mat a) {
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
int rk(mat a, int& f) {
    const int n = a.size(), m = a[0].size();
    int i = 0;
    for (int j = 0; i != n && j != m; j++) {
        for (int k = j + 1; !a[i][j] && k < n; ++k)
            if (a[k][j]) swap(a[k], a[j]);
        if (!a[i][j]) { f = i; continue; }
        for (int k = i + 1, t = inv(a[i][j]); k < n; ++k)
            for (int l = j, w = mul(a[k][j], t); l < m; ++l)
                a[k][l] = sub(a[k][l], mul(w, a[i][l]));
        i++;
    }
    return i;
}

bool adj0(mat& b) {
    const int n = b.size(); int d = 1;
    mat a(n, vec(2 * n, 0));
    for (int i = 0; i < n; ++i) {
        copy_n(b[i].begin(), n, a[i].begin());
        a[i][n + i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && !a[i][i]; ++j)
            if (a[j][i]) swap(a[i], a[j]), d = sub(0, d);
        d = mul(d, a[i][i]);
        for (int j = i, t = inv(a[i][i]); j < 2 * n; ++j)
            a[i][j] = mul(a[i][j], t);
        for (int j = 0; j < n; ++j) if(j != i)
            for (int k = i, t = a[j][i]; k < 2 * n; ++k)
                a[j][k] = sub(a[j][k], mul(t, a[i][k]));
    }
    if (!d) return false;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j)
            b[i][j] = mul(a[i][n + j], d);
    return true;
}

mat adj(mat a) {
    int n = a.size(), fi, fj;
    if (n == 1)
        return mat(1, vec(1, a[0][0] ? 1 : 0));
    int r = rk(a, fj);
    if (r == n) { adj0(a); return a; }
    if (r <= n - 2) return mat(n, vec(n, 0));
    uniform_int_distribution<int> uid(0, P - 1);
    mt19937_64 mt(chrono::system_clock::now().time_since_epoch().count());
    mat b(n, vec(n, 0)), c = a;
    do for (int i = 0; i < n; ++i) c[i][fj] = uid(mt);
    while (!adj0(c));
    for (int i = 0; i < n; ++i) b[fj][i] = c[fj][i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            c[i][j] = a[j][i];
    rk(c, fi);
    do for (int j = 0; j < n; ++j) c[j][fi] = uid(mt);
    while (!adj0(c));
    for (int j = 0; j < n; ++j) b[j][fi] = c[fi][j];
    int w = inv(b[fj][fi]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != fj && j != fi)
                b[i][j] = mul(mul(b[fj][j], b[i][fi]), w);
    return b;
}

template<class T>
void print(T f, mat m) {
    for (int i = 0; i < m.size(); ++i)
        for (int j = 0; j < m[i].size(); ++j)
            fprintf(f, "%d%c", m[i][j], " \n"[j + 1 == m[i].size()]);
}

mat get_a(int n) {
    mat a(n, vec(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = uniform_int_distribution<int>(0, P - 1)(mt);
    
    vec w(n);
    for (int i = 0; i < n; ++i)
        if (mt() % 3 == 0)
            w[i] = uniform_int_distribution<int>(0, P - 1)(mt);
    int x = uniform_int_distribution<int>(0, n - 1)(mt);
    w[x] = 0;
    if (mt() % 2) for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < n; ++j)
            s = add(s, mul(a[i][j], w[j]));
        a[i][x] = s;
    }
    else for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < n; ++j)
            s = add(s, mul(a[j][i], w[j]));
        a[x][i] = s;
    }
    if (rk(a, x) != n - 1)
        return get_a(n);
    return a;
}

int main(void) {
    int n; scanf("%d", &n);
    while (1) {
        mat a(n, vec(n));
        a = get_a(n);
        // for (int i = 0; i < n; ++i)
        //     for (int j = 0; j < n; ++j)
        //         scanf("%d", &a[i][j]);
        mat b0 = adj_bf(a), b = adj(a);
        //assert(b0 == b);
        print(stdout, a);
        if (b0 != b) {
            printf("Wrong Answer\n");
            print(stdout, b);
            print(stdout, b0);
            printf("%d\n", n);
            print(stdout, a);
            break;
        }
        else {
            printf("Accepted\n");
        }
    }
    return 0;
}