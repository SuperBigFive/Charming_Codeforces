#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	string s;
	cin >> s, s = '#' + s;
	vector <array <int, 2> > dp (n + 5);
	ll ans = 0;
	for (int i = 1, ch2num; i <= n; ++i) {
		ch2num = s[i] - '0';
		if (ch2num == 0) {
			dp[i][0] = 0;
			dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
		}
		else {
			dp[i][0] = dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
		}
		++dp[i][ch2num];
		ans += dp[i][1];
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}