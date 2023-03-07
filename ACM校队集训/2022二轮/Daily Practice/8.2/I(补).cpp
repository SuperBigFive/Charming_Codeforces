#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 2e4 + 5;

int n, m;
int val[maxn], t[maxn];
int dp[105][2605][105];

void init () {
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 2600; ++j) {
			for (int k = 0; k <= 100; ++k) {
				dp[i][j][k] = -LONG_MAX;
			}
		}
	}
	dp[0][1300][0] = 0;
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i] >> t[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 2600; ++j) {
			for (int k = 0; k <= m; ++k){
				dp[i][j][k] = dp[i - 1][j][k];
				if (j >= 2 * t[i] && k) {
					dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j - 2 * t[i]][k - 1] + val[i]);
				}
				if (j >= t[i]) {
					dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j - t[i]][k] + val[i]);
				}
				if (j + t[i] <= 2600) {
					dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j + t[i]][k] + val[i]);
				}
				if (j + 2 * t[i] <= 2600 && k) {
					dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j + 2 * t[i]][k - 1] + val[i]);
				}
			}
		}
	}
	ll ans = -LONG_MAX;
	for (int i = 0; i <= m; ++i) {
		ans = max (ans, dp[n][1300][i]);
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}