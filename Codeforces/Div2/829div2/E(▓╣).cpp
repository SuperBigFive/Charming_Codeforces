#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;

int t, n;
int a[maxn];

void init () {}

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

ll dfs (ll cur_n, ll good) {
	if (!good) return 0;
	ll last = dfs (cur_n, good - 1), x, y;
	ll mo = cur_n * (cur_n - 1) / 2 % mod, son = good * good;
	ex_gcd (son, mod, x, y);
	x = ((x % mod) + mod) % mod;
	mo = (mo * x) % mod;
	return last + mo;
}

void charming () {
	init ();
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i]) ++cnt;
	}
	ll valid = 0, invalid;
	for (int i = n - cnt + 1; i <= n; ++i) {
		if (a[i]) ++valid;
	}
	invalid = cnt - valid;
	ll res = dfs (n, invalid);
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}