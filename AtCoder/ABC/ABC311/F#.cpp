#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <int> > isBlack (n + 5, vector <int> (m + 5));
	string s;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			isBlack[i][j] = ((s[j - 1] == '#') | isBlack[i - 1][j - 1] | isBlack[i - 1][j]);
		}
	}
	vector <vector <int> > dp (m + 5, vector <int> (n + 5));
	for (int i = 0; i <= n + 1; ++i) dp[0][i] = 1;
	for (int i = 1, lim; i <= m; ++i) {
		for (int j = n + 1; j >= 1; --j) {
			if (isBlack[j - 1][i]) continue;
			else dp[i][j] = (dp[i][j + 1] + dp[i - 1][j - 1]) % MOD;
		}
		dp[i][0] = dp[i][1];
	}
	ll ans = dp[m][0];
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}