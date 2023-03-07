#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;

int t;
ll n, k;
ll dp[maxn], sum[maxn];

void init () {}

ll qsm (ll num, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = (res * num) % mod;
		p >>= 1;
		num = (num * num) % mod;
	}
	return res;
}

void get_dp () {
	dp[1] = 0, sum[1] = 0;
	for (int i = 2; i < maxn; ++i) {
		ll inv = qsm (i - 1, mod - 2) % mod;
		dp[i] = (1 + sum[i - 1] * inv) % mod;
		sum[i] = (sum[i - 1] + dp[i]) % mod;
	}
}

void charming () {
	init ();
	scanf ("%lld%lld", &n, &k);
	ll res = dp[k + 1] % mod;
	res = (res * n) % mod;
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	get_dp ();
	scanf ("%lld", &t);
	while (t--) charming ();
	return 0;
}