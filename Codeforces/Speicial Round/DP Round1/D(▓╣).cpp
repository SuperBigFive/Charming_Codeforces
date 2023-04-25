#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e3 + 5;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	s = '#' + s, t = '#' + t;
	vector <vector <int> > dp (n + 1, vector <int> (m + 1));
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 2;
			else dp[i][j] = max (0ll, 
			max (dp[i - 1][j], dp[i][j - 1]) - 1);
			res = max (res, dp[i][j]);
		}
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}