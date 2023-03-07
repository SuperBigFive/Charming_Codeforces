#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e3 + 5;
const int mod = 998244353;

int n, m, invm, k;
int dp[maxn][maxn];

void init () {
	dp[0][0] = 1;
}

ll ex_gcd (ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	ll GCD = ex_gcd (b, a % b, x, y);
	ll tmp = y;
	y = x - (a / b) * y;
	x = tmp;
	return GCD;
}

void charming () {
	init ();
	cin >> n >> m >> k;
	ll y;
	ex_gcd (m, mod, invm, y);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int q = 1; q <= m; ++q) {
				int nxt = j + q;
				if (nxt > n) nxt = n - (nxt - n);
				dp[i + 1][nxt] = (dp[i + 1][nxt] + invm * dp[i][j]) % mod;
			}
		}
	}
	ll res = 0;
	for (int i = 0; i <= k; ++i)
	res = (res + dp[i][n]) % mod;
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}