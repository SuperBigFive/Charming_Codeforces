#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e2 + 5;

int n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	string s, t;
	cin >> s >> t, s = '#' + s;
	if (t[0] == t[1]) {
		int cnt = 0;
		for (auto &ch : s) if (ch == t[0]) ++cnt;
		cnt = min (n, cnt + k);
		cout << cnt * (cnt - 1) / 2 << endl;
		return;
	}
	vector <vector <vector <int> > > dp (n + 5,
	vector <vector <int> > (k + 5, vector <int> (n + 5, -1)));
	int res = 0;
	dp[0][0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int p = 0; p <= n; ++p) {
				if (dp[i][j][p] <= -1) continue;
				dp[i + 1][j][p] = max (dp[i + 1][j][p], dp[i][j][p]);
				dp[i + 1][j + 1][p + 1] = max (dp[i + 1][j + 1][p + 1], dp[i][j][p]);
				dp[i + 1][j + 1][p] = max (dp[i + 1][j + 1][p], dp[i][j][p] + p);
				if (s[i + 1] == t[0]) dp[i + 1][j][p + 1] = max (dp[i + 1][j][p + 1], dp[i][j][p]);
				if (s[i + 1] == t[1]) dp[i + 1][j][p] = max (dp[i + 1][j][p], dp[i][j][p] + p);
			}
		}
	}
	for (int i = 0; i <= n; ++i)
	for (int j = 0; j <= k; ++j)
	for (int p = 0; p <= n; ++p)
	res = max (res, dp[i][j][p]);
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}