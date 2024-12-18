#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18;
const int P = 998244353;

typedef vector<int> vi;

inline int add(int a, int b) { int r = a + b; return r < P ? r : r - P; }
inline int sub(int a, int b) { int r = a - b; return r < 0 ? r + P : r; }
inline int mul(long long a, long long b) { return a * b % P; }
inline int inv(int a) { return a == 1 ? a : mul(inv(P % a), P - P / a); }
inline int qpm(int a, int b) {
    int r = 1;
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}

int S(int n, int q, int k) {
    int sum = 0;
    for (int i = 0; i <= n; ++i)
        sum = add(sum, mul(qpm(i, k), qpm(q, i)));
    return sum;
}

int S0(int n, int q) {
    return mul(sub(qpm(q, n + 1), 1), inv(sub(q, 1)));
}

int main(void) {
    const int n = 100, q = 114514;
    int s[n + 1], bi[101][101];
    for (int i = 0; i <= n; ++i)
        for (int j = bi[i][0] = bi[i][i] = 1; j < i; ++j)
            bi[i][j] = add(bi[i - 1][j - 1], bi[i - 1][j]);    s[0] = S0(n, q);
    for (int k = 1; k <= n; ++k) {
        s[k] = mul(qpm(n + 1, k), qpm(q, n + 1));
        for (int j = 0; j <= k - 1; ++j)
            s[k] = sub(s[k], mul(q, mul(bi[k][j], s[j])));
        s[k] = mul(s[k], inv(q - 1));
        cout << s[k] << ' ' << S(n, q, k) << endl;
    }
    return 0;
}