#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;

int n, m, k;
ll fac[maxn], inv[maxn];

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

void get_fac () {
	fac[0] = 1, inv[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
		inv[i] = qsm (fac[i], mod - 2);
	}
}

ll C (ll nn, ll mm) {return ((fac[nn] * inv[mm] % mod) * inv[nn - mm]) % mod;}

void charming () {
	init ();	
	cin >> n >> m >> k;
	if (k == 0) {
		cout << (m == 0) << endl;
		return;
	}
	ll res1 = 0, res2 = 0;
	for (int i = 1; i * k <= m; ++i) {
		res1 = (res1 + (i & 1 ? 1 : -1) * C (n - m + 1, i) 
		* (C (n - i * k, n - m))) % mod;
	}
	++k;
	for (int i = 1; i * k <= m; ++i) {
		res2 = (res2 + (i & 1 ? 1 : -1) * C (n - m + 1, i)
		* (C (n - i * k, n - m))) % mod;
	}
	ll res = ((res1 - res2) % mod + mod) % mod;
	cout << res << endl;
}

signed main () {
	get_fac ();
 	charming ();
	return 0;
}