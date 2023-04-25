#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e3 + 5;

int t, n, x;
int a[maxn];
int dp[maxn][maxn];

void init () {
	for (int i = 0; i <= n; ++i)
	for (int j = i; j <= n; ++j)
	dp[i][j] = 0;
}

void charming () {
	init ();	
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	vector <pair <int, int> > ans;
	for (int len = 1; len <= n; ++len) {
		int mx = -INT_MAX;
		for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
			if (len == 1) dp[i][j] = a[i];
			else dp[i][j] = dp[i][j - 1] + a[j];
			mx = max (mx, dp[i][j]);
		}
		ans.emplace_back (make_pair (mx, len));
	}
	for (int i = 0; i <= n; ++i) {
		int res = 0;
		for (auto it : ans) res = max (res, it.first + min (it.second, i) * x);
		cout << res << " \n"[i == n];
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}