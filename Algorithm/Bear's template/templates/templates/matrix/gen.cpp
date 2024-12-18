#include <bits/stdc++.h>
using namespace std;

mt19937_64 mt(chrono::system_clock::now().time_since_epoch().count());

int p;
#define P p
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


int main(int, char** argv) {
    int n = atoi(argv[1]);
    p = atoi(argv[2]);
    uniform_int_distribution<int> uid(0, p - 1);
    printf("%d %d\n", n, p);
    
    typedef vector<int> vec;
    typedef vector<vec> mat;
    mat r(n, vec(n, 0));
    for (int i = 0; i < n - 1; ++i) {
        int w = uid(mt);
        for (int j = 0; j < n; ++j) {
            r[i][j] = uid(mt);
            r[n - 1][j] = add(r[n - 1][j], mul(r[i][j], w));
        }
    }

    for (int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j)
            printf("%d%c", r[i][j], " \n"[j + 1 == n]);

    return 0;
}

