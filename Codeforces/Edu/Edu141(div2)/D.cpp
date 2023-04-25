#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e2 + 5;
const int M = 1e5 + 5;
const int mod = 998244353;

int t, n;

void init () {}

ll add (ll &x, ll &y) {return (x + y) % mod;}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5);
	vector <vector <int> > dp (n + 5, vector <int> (M << 1, 0));
	for (int i = 1; i <= n; ++i) cin >> a[i];
	dp[3][a[3] + a[2] + M] = 1, dp[3][a[3] - a[2] + M] = 1;
	for (int i = 3; i < n; ++i) {
		for (int j = 0; j < M << 1; ++j) {
			if (dp[i][j] <= 0) continue;
			dp[i + 1][a[i + 1] + j] = add (dp[i + 1][a[i + 1] + j], dp[i][j]);
			if (j != M) dp[i + 1][a[i + 1] - j + 2 * M] = add (dp[i + 1][a[i + 1] - j + 2 * M], dp[i][j]);
			//cout << i + 1 << " " << a[i + 1] + j << " :" << dp[i + 1][a[i + 1] + j] << endl;
			//cout << i + 1 << " " << a[i + 1] - j + 2 * M << " :" << dp[i + 1][a[i + 1] - j + 2 * M] << endl;
		}
	}
	int res = 0;
	for (int i = 0; i < M << 1; ++i) {
		res = add (res, dp[n][i]);
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}