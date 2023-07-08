#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e4 + 5;
const int M = 2e3 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	for (auto &it : a) cin >> it;
	vector <vector <int> > dp (n + 1, vector <int> (M, INT_MAX));
	int res = INT_MAX;
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < M; ++j) {
			if (dp[i][j] >= INT_MAX) continue;
			dp[i + 1][max (0ll, j - a[i])] = min (dp[i][j] + a[i],
			dp[i + 1][max (0ll, j - a[i])]);
			if (j + a[i] < M) {
				dp[i + 1][j + a[i]] = min (dp[i + 1][j + a[i]],
				max (dp[i][j] - a[i], 0ll));
			}
		}
	}
	for (int i = 0; i < M; ++i) {
		res = min (res, i + dp[n][i]);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}