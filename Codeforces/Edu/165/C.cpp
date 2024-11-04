#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void charming () {
  cin >> n >> k;
  vector <int> a (n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector <vector <ll> > dp (n, vector <ll> (k + 1, 1ll * INT_MAX * N));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (i - 1 >= 0) dp[i][j] = dp[i - 1][j] + a[i];
      else dp[i][j] = a[i];
    }
    int mn = (i + 1 < n ? a[i + 1] : INT_MAX);
    for (int j = 1; j <= min (i + 1, k); ++j) {
      mn = min (mn, i - j >= 0 ? a[i - j] : INT_MAX);
      if (i - j - 1 >= 0) {
        for (int p = j; p <= k; ++p) {
          dp[i][p] = min (dp[i][p], dp[i - j - 1][p - j] + 1ll * mn * j + a[i - j]);
        }
      }
      else {
        for (int p = j; p <= k; ++p) {
          dp[i][p] = min (dp[i][p], 1ll * mn * j + (i - j >= 0 ? a[i - j] : 0));
        }
      }
    }
  }
  cout << dp[n - 1][k] << endl;

  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j <= k; ++j) cout << i << " " << j << " " << dp[i][j] << endl;
  // }
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}