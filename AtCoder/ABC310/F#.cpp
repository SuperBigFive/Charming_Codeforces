#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;

ll QSM (ll x, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) ans = (ans * x) % MOD;
		p >>= 1, x = (x * x) % MOD;
	}
	return ans;
}

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1);
	ll mo = 1;
	for (int i = 1; i <= n; ++i) cin >> a[i], mo = (mo * a[i]) % MOD;
	int lim = 1 << 11;
	vector <vector <int> > dp (2, vector <int> (lim));
	dp[0][1] = 1;
	for (int i = 0; i < n; ++i) {
		dp[(i + 1) & 1] = vector <int> (lim);
		for (int st = 1, nst; st < lim; ++st) {
			for (int j = 1; j <= min (10ll, a[i + 1]); ++j) {
				nst = st;
				for (int k = 0; k <= 10 - j; ++k) {
					if ((st >> k) & 1) nst |= (1 << (k + j));
				}
				dp[(i + 1) & 1][nst] = (dp[(i + 1) & 1][nst] + dp[i & 1][st]) % MOD;
			}
			if (a[i + 1] > 10) {
				dp[(i + 1) & 1][st] = (dp[(i + 1) & 1][st] + 
				dp[i & 1][st] * (a[i + 1] - 10)) % MOD;
			}
		}
	}
	ll ans = 0;
	for (int i = (1 << 10); i < lim; ++i) {
		ans = (ans + dp[n & 1][i]) % MOD;
	}
	ans = (ans * QSM (mo, MOD - 2)) % MOD;
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}