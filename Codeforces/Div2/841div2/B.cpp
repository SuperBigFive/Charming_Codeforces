#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int t, n, inv6;

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

ll cal (ll num) {
	ll res = 1;
	res = (res * num) % mod;
	res = (res * (num + 1)) % mod;
	res = (res * (num * 2 + 1)) % mod;
	res = (res * inv6) % mod;
	return ((res % mod) + mod) % mod;
}

void charming () {
	init ();
	cin >> n;
	ll res = (cal (n) * 2 - 1 - (n - 1) * (n + 2) / 2) % mod;
	res = (res * 2022) % mod;
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	inv6 = qsm (6, mod - 2);
	cin >> t;
	while (t--) charming ();
	return 0;
}