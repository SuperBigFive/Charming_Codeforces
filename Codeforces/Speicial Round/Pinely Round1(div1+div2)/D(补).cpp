#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;

int n, k;
ll fac[maxn], inv[maxn], POW3[maxn];

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

void get () {
	fac[0] = inv[0] = POW3[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
		inv[i] = qsm (fac[i], mod - 2);
		POW3[i] = (POW3[i - 1] * 3) % mod;
	}
}

ll cal (int nn, int mm, int pp) {
	if (pp < 0 || nn < mm) return 0;
	ll res = 1;
	res = (((fac[nn] * inv[mm]) % mod) * inv[nn - mm]) % mod;
	res = (res * (POW3[pp] % mod)) % mod;
	res = ((res % mod) + mod) % mod;
	return res;
}

void charming () {
	init ();
	cin >> n >> k;
	if (!k) {cout << POW3[n] << endl; return;}
	ll res = 0, tmp;
	for (int i = 1; i <= k; ++i) {
		tmp = (cal (k - 1, i - 1, k - i)) % mod;
		tmp = (tmp * ((cal (n - k, i, n - k - i) 
		+ cal (n - k, i - 1, n - k - i + 1)) % mod)) % mod;
		res = (res + tmp) % mod;
	}
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	get ();
	charming ();
	return 0;
}