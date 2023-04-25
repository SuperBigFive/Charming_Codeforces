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
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;

int t;
ll fac[maxn];

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

void get_fac () {
	fac[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
}

ll get_inv (ll num) {
	ll x, y;
	ex_gcd (num, mod, x, y);
	return ((x % mod) + mod) % mod;
}

ll get_c (ll n, ll m) {
	return ((fac[n] * get_inv (fac[n - m])) % mod * get_inv (fac[m])) % mod;
}

void charming () {
	ll n, m;
	cin >> n >> m;
	ll ans = get_c (n + m, n);
	if (n < m) ans -= get_c (m - 1, n);
	ans = (ans % mod + mod) % mod;
	cout << ans << endl;
}

signed main () {
	get_fac ();
	cin >> t;
	while (t--) charming ();
	return 0;
}