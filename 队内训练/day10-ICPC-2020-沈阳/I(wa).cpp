#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int h, m, a;

void init () {}

void charming () {
	init ();
	cin >> h >> m >> a;
	int res = 0;
	for (int i = 0; i < h * m; ++i) {
		int val = (h - 1) * i % (h * m);
		if (val <= a || val >= h * m - a) ++res;
	}
	cout << res << endl;
	
	auto qsm = [&] (ll num, ll p, ll mod) -> ll {
		ll res = 1;
		while (p) {
			if (p & 1) res = (res * num) % mod;
			p >>= 1;
			num = (num * num) % mod;
		}
		return res;
	};
	
	auto cal = [&] (ll a, ll b, ll c) -> ll {
		ll GCD = __gcd (a, b);
		a /= GCD, b /= GCD, c /= GCD;
		ll inv_a = qsm (a, b - 2, b);
		return (h * m - 1) / inv_a + 1;
	};
	cout << cal (h - 1, h * m, a) + h * m
	- cal (h - 1, h * m, h * m - a - 1) << endl;
}

signed main () {
	charming ();
	return 0;
}