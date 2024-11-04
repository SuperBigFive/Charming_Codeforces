#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e3 + 5;
const int MOD = 998244353;

int n;
int inv2[N], dp[N][N];

int QSM (int x, int p) {
    int ans = 1;
    while (p) {
        if (p & 1) ans = 1ll * ans * x % MOD;
        x = 1ll * x * x % MOD, p >>= 1;
    }
    return ans;
}

void charming () {
    dp[1][1] = 1;
    inv2[0] = 1;
    for (int i = 1, pow2 = 1; i < N; ++i) {
        pow2 = pow2 * 2 % MOD;
        inv2[i] = QSM (pow2, MOD - 2);
    }
    for (int i = 2; i < N; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][1] = (dp[i][1] + 1ll * inv2[j] * dp[i - 1][(i - j + 1) % i] % MOD) % MOD;
        }
        dp[i][1] = 1ll * dp[i][1] * QSM (1 - inv2[i] + MOD, MOD - 2) % MOD;
        for (int j = 2; j <= i; ++j) {
            dp[i][j] = 1ll * inv2[1] * (dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
        }
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        // dp[n][i] = ((dp[n][i] % MOD) + MOD) % MOD;
        cout << dp[n][i] << " \n"[i == n];
    }
}

signed main () {
    charming ();
    return 0;
}