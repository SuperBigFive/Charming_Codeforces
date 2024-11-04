#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;
const int MOD = 998244353;

int n, ans;
int a[N];
int dp[2][N];

void charming () {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort (a + 1, a + 1 + n);
  dp[0][0] = 1;
  for (int i = 1, now, lst; i <= n; ++i) {
    now = i & 1, lst = now ^ 1;
    for (int j = 0; j < N; ++j) {
      dp[now][j] = dp[lst][j];
      if (j - a[i] >= 0) {
        dp[now][j] = (dp[now][j] + dp[lst][j - a[i]]) % MOD;
        if (j - a[i] > a[i]) ans = (ans + 1ll * dp[lst][j - a[i]] * ((j + 1) / 2) % MOD) % MOD;
        else ans = (ans + 1ll * dp[lst][j - a[i]] * a[i] % MOD) % MOD;
      }
    }
    for (int j = 0; j < N; ++j) dp[lst][j] = 0;
  }
  cout << ans << endl;
}

signed main () {
  charming ();
  return 0;
}