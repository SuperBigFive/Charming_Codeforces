#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int t, n, id1, x, id2, y;
int fac[N], inv[N];

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
	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
		inv[i] = qsm (fac[i], mod - 2);
	}
}

ll C (int nn, int mm) {
	if (mm > nn || mm < 0 || nn < 0) return 0;
	return (((fac[nn] * (inv[nn - mm])) % mod) * inv[mm]) % mod;
}

void charming () {
	init ();
	cin >> n >> id1 >> id2 >> x >> y;
	if (x == n) {
		int d1 = x - y - 1, d2 = id2 - 2;
		if (d2 < d1 || id1 <= 1) {
			cout << 0 << endl;
			return;
		}
		ll res = C (d1, id2 - id1 - 1) % mod;
		res = (res * C (y - 1, n - id2)) % mod;
		res = ((res % mod) + mod) % mod;
		cout << res << endl;
	}
	else if (y == n) {
		int d1 = y - x - 1, d2 = n - id1 - 1;
		if (d2 < d1 || id2 >= n) {
			cout << 0 << endl;
			return;
		}
		ll res = C (d1, id2 - id1 - 1) % mod;
		res = (res * C (x - 1, id1 - 1)) % mod;
		res = ((res % mod) + mod) % mod;
		cout << res << endl;
	}
	else {
		ll res = 0;
		int d1 = n - max (x, y) - 1, d2 = abs (x - y) - 1;
		for (int i = id1 + 1; i < id2; ++i) {
			int d3 = id2 - i - 1, d4 = id2 - id1 - 1 - n + max (x, y);
			int tmp = C (d1, d3) * C (d2, d4) % mod;
			if (x < y) tmp = (tmp * C (min (x, y) - 1, id1 - 1)) % mod;
			else tmp = (tmp * C (min (x, y) - 1, n - id2));
			res = (res + tmp) % mod;
		}
		if (x < y) {
			for (int i = id2 + 1; i < n; ++i) {
				int d3 = i - id2 - 1, d4 = id2 - id1 - 1;
				int tmp = C (d1, d3) * C (d2, d4) % mod;
				tmp = (tmp * C (x - 1, id1 - 1)) % mod;
				res = (res + tmp) % mod;
			}
		}
		else {
			for (int i = id1 - 1; i > 1; --i) {
				int d3 = id1 - i - 1, d4 = id2 - id1 - 1;
				int tmp = C (d1, d3) * C (d2, d4) % mod;
				tmp = (tmp * C (y - 1, n - id2)) % mod;
				res = (res + tmp) % mod;
			}
		}
		res = ((res % mod) + mod) % mod;
		cout << res << endl;
	}
}

signed main () {
	get ();
	cin >> t;
	while (t--) charming ();
	return 0;
}