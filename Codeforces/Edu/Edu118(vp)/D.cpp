#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;

int t, n;
ll val[maxn], pow2[maxn], dp[maxn][2];

void get_pow2 () {
	pow2[0] = 1;
	for (int i = 1; i < maxn; ++i) pow2[i] = (pow2[i - 1] << 1) % mod;
}

void init () {
	for (int i = 0; i <= n + 1; ++i) dp[i][0] = dp[i][1] = 0;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	int cnt1 = 0;
	for (int i = 1; i <= n; ++i) {
		dp[val[i] + 1][0] = (dp[val[i] + 1][0] << 1) % mod;
		dp[val[i] + 1][0] = (dp[val[i] + 1][0] + dp[val[i]][0]) % mod;
		dp[val[i] + 1][1] = (dp[val[i] + 1][1] << 1) % mod;
		
		dp[val[i] - 1][1] = ((dp[val[i] - 1][1] << 1) + dp[val[i] - 1][0]) % mod;
		if (!val[i]) dp[1][0] = (dp[1][0] + 1) % mod;
		if (val[i] == 1) ++cnt1;
	}
	ll res = 0;
	for (int i = 1; i <= n + 1; ++i) {
		res = (res + dp[i][0] + dp[i][1]) % mod;
	}
	res = (res + pow2[cnt1] - 1) % mod;
	res = (res % mod + mod) % mod;
	cout << res << endl;
}

signed main () {
	get_pow2 ();
	cin >> t;
	while (t--) charming ();
	return 0;
}