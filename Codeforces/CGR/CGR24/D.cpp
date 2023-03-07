#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, mod;
int fac[N], inv[N];

void init () {}

ll qsm (ll num, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = (res * num) % mod;
		p >>= 1;
		num = (num * num) % mod;
	}
	res = ((res % mod) + mod) % mod;
	return res;
}

ll C (ll nn, ll mm) {
	if (nn < mm) return 0;
	ll res = (((fac[nn] * inv[mm]) % mod) 
	* inv[nn - mm]) % mod;
	res = ((res % mod) + mod) % mod;
	return res;
}

void get () {
	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
		inv[i] = qsm (fac[i], mod - 2);
	}
}

void charming () {
	init ();
	cin >> n >> mod;
	get ();
	ll res = 0;
	if (!(n & 1)) {
		for (int i = 0; i <= n / 2  - 1; ++i) {
			ll val = 0;
			for (int j = 0; j <= max (0ll, i - 1); ++j) {
				val = (val + C (max (0ll, i - 1), j) 
				* fac[n - 2 - (i > 0) - j]) % mod;
			}
			val = (val * (i + 1)) % mod;
			res = (res + val) % mod;
		}
	}
	else {
		for (int i = 1; i <= n / 2; ++i) {
			ll val = 0;
			for (int j = 0; j <= max (0ll, i - 1); ++j) {
				val = (val + C (max (0ll, i - 1), j) 
				* fac[n - 3 - j]) % mod;
			}
			val = (val * i) % mod;
			res = (res + val) % mod;
		}
	}
	res = (res * n) % mod;
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}