#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;

int n;
ll k = 1;
char s[maxn];
ll dp[maxn][3];

void update (ll tot, ll add0, ll add1, ll add2) {
	dp[tot][0] = (dp[tot-1][0] + add0) % mod;
	dp[tot][1] = (dp[tot-1][1] + add1) % mod;
	dp[tot][2] = (dp[tot-1][2] + add2) % mod;
}

void charming () {
	cin >> n;
	cin >> s + 1;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'a') update (i, k, 0, 0);
		else if (s[i] == 'b') update (i, 0, dp[i-1][0], 0);
		else if (s[i] == 'c') update (i, 0, 0, dp[i-1][1]);
		else if (s[i] == '?') update (i, 2 * dp[i-1][0] + k, 2 * dp[i-1][1] + dp[i-1][0], 2 * dp[i-1][2] + dp[i-1][1]), k = k * 3 % mod;
	}
	cout << dp[n][2] % mod << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0; 
}
