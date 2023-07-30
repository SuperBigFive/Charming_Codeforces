#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;

int n;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s, n = s.size ();
	vector <int> dp (n + 5, 0), ndp;
	dp[0] = 1;
	for (auto ch : s) {
		ndp = vector <int> (n + 5, 0);
		for (int i = 0; i <= n; ++i) {
			if (ch != '(' && i) ndp[i - 1] = (ndp[i - 1] + dp[i]) % MOD;
			if (ch != ')') ndp[i + 1] = (ndp[i + 1] + dp[i]) % MOD;
		}
		dp = ndp;
	}
	cout << dp[0] << endl;
}

signed main () {
	charming ();
	return 0;
}