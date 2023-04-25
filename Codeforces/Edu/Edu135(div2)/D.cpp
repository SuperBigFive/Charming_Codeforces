#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e3 + 5;

int t, n;
int dp[maxn][maxn];
char s[maxn];

void init () {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) dp[i][j] = 0;
	}
}

int get (int l, int r, char ch1, char ch2) {
	int chk = dp[l][r];
	if (chk == 1) return 1;
	else if (chk == 2) {
		if (ch1 == ch2) return 2;
		else return 1;
	}
	else return 3;
}

void charming () {
	init ();
	cin >> s + 1;
	n = strlen (s + 1);
	for (int len = 2; len <= n; len += 2) {
		for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
			if (len == 2) {
				if (s[i] != s[j]) dp[i][j] = 1;
				else dp[i][j] = 2;
				continue;
			}
			
			int ok1, ok2, ok3;
			ok1 = get (i, j - 2, s[j], s[j - 1]);
			ok2 = get (i + 1, j - 1, s[i], s[j]);
			ok3 = get (i + 2, j, s[i], s[i + 1]);
			
			if (ok2 == 3) dp[i][j] = 3;
			else if (ok2 == 2) {
				if (ok1 == 3 && ok3 == 3) dp[i][j] = 3;
				else dp[i][j] = 2;
			}
			else {
				if (ok1 == 3 && ok3 == 3) dp[i][j] = 3;
				else if (ok1 >= 2 && ok3 >= 2) dp[i][j] = 2;
				else dp[i][j] = 1;
			}
		}
	}
	if (dp[1][n] == 1) cout << "Alice" << endl;
	else if (dp[1][n] == 2) cout << "Draw" << endl;
	else cout << "Bob" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}