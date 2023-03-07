#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int>
#define pip pair <int, pii> 
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;

int t, len, tot;
ll sum[maxn], pos[maxn], cnt[maxn], plans[maxn], pow2[maxn];
char str[maxn];
ll dp[10][maxn];

void init () {
	for (int i = 1; i <= len; ++i) {
		cnt[i] = 0;
		for (int j = 1; j <= 8; ++j) dp[j][i] = 0;
	}
}

void get_pow2 () {
	pow2[0] = 1;
	for (int i = 1; i <= 100005; ++i) {
		pow2[i] = (pow2[i - 1] << 1) % mod;
	}
}

void charming () {
	init ();
	cin >> str + 1;
	len = strlen (str + 1);
	for (int i = len; i >= 1; --i) {
		cnt[i] = cnt[i + 1];
		if (str[i] == 'a') ++cnt[i];
	}
	for (int i = 1; i <= len; ++i) {
		for (int j = 1; j <= 8; ++j) {
			dp[j][i] = dp[j][i - 1];
		}
		if (str[i] == 'n') {
			++dp[1][i];
			dp[3][i] = (dp[2][i] + dp[3][i]) % mod;
		}
		else if (str[i] == 'u') {
			dp[2][i] = (dp[1][i] + dp[2][i]) % mod;
		}
		else if (str[i] == 'e') {
			dp[5][i] = (dp[4][i] + dp[5][i]) % mod;
			dp[8][i] = (dp[7][i] + dp[8][i]) % mod;
		}
		else if (str[i] == 'h') {
			dp[4][i] = (dp[3][i] + dp[4][i]) % mod;
			dp[7][i] = (dp[6][i] + dp[7][i]) % mod;
			dp[6][i] = (dp[5][i] + dp[6][i]) % mod;
		}
	}
	ll res = 0;
	for (int i = 1; i <= len; ++i) {
		if (str[i] == 'h') {
			 res = (res + dp[8][i - 1] * (pow2[cnt[i]] - 1)) % mod;
		}
	}
	cout << res << endl;
}

signed main() {
	get_pow2 ();
	cin >> t;
	while (t--) charming ();
	return 0;
}
