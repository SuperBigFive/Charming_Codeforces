#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 100;
const int mod = 998244353;

int t, n;
int fac[maxn], inv[maxn];
int dp[maxn];

ll ex_gcd (ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	ll GCD = ex_gcd (b, a % b, x, y);
	ll tmp = y;
	y = x - a / b * y;
	x = tmp;
	return GCD;
}

void get_fac () {
	fac[0] = inv[0] = 1;
	for (int i = 1, x, y; i < maxn; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
		ex_gcd (fac[i], mod, x, y);
		inv[i] = ((x % mod) + mod) % mod;
	}
}

ll get_c (ll nn, ll mm) {
	return (((fac[nn] * inv[nn - mm]) % mod * inv[mm]) % mod + mod) % mod;
}

void get_ans () {
	dp[2] = 1, dp[4] = 3;
	for (int i = 6; i <= 60; i += 2) {
		dp[i] = get_c (i - 1, i / 2) + get_c (i - 4, i / 2 - 3) + dp[i - 4];
		dp[i] = ((dp[i] % mod) + mod) % mod;
	}
}

void charming () {
	cin >> n;
	int win = dp[n];
	int lose = get_c (n, n / 2) - dp[n] - 1;
	lose = ((lose % mod) + mod) % mod;
	cout << win << " " << lose << " " << 1 << endl;
}

signed main () {
	get_fac ();
	get_ans ();
	cin >> t;
	while (t--) charming ();
	return 0;
}