#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007, N = 1001;

typedef long long ll;
int add(int a, int b) { int r = a + b; return r < P ? r : r - P; }
int sub(int a, int b) { int r = a - b; return r < 0 ? r + P : r; }
int mul(int a, int b) { return 1ll * a * b % P; }
int qpm(int a, ll b) {
    int r = 1;
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}
int inv(int x) { return qpm(x, P - 2); }

int invs[N], fac[N], ifac[N];
int bi[N][N], be[N], ep[N][N];
void ginv() {
    invs[1] = 1; fac[0] = ifac[0] = 1;
    for (int i = 2; i != N; ++i) invs[i] = mul(invs[P % i], (P - P / i));
    for (int i = 1; i != N; ++i) fac[i] = mul(fac[i - 1], i);
    for (int i = 1; i != N; ++i) ifac[i] = mul(ifac[i - 1], invs[i]);
    // Binomial coefficient
    for (int i = 0; i != N; ++i)
        for (int j = bi[i][0] = bi[i][i] = 1; j < i; ++j)
            bi[i][j] = add(bi[i - 1][j - 1], bi[i - 1][j]);
    be[0] = 1;  //  Bernoulli numbers
    for (int i = 1; i != N; ++i)
        for (int j = 0; j != i; ++j)
            be[i] = sub(be[i], mul(bi[i][j], mul(be[j], invs[i - j + 1])));
    //  Equal Power Sum Coef
    ep[0][0] = ep[0][1] = 1;
    for (int i = 1; i != N; ++i)
        for (int j = 0; j <= i; ++j)
            ep[i][i+1-j]=mul((j&1?sub:add)(0,invs[i+1]),mul(bi[i + 1][j],be[j]));
}