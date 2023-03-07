#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 998244353;

ll n, m;
queue <pair <int, int> > prim;

void init () {}

void get_prim () {
	prim.push (make_pair (1, 1));
	for (int i = 2, mul = 1;; ++i) {
		bool ok = true;
		for (int j = 2; j * j <= i; ++j) {
			if (!(i % j)) ok = false;
		}
		if (!ok) continue;
		mul = mul * i;
		prim.push (make_pair (mul, i));
		if (mul > m) {
			prim.push (make_pair (mul, i));
			break;
		}
	}
}
			
void charming () {
	init ();
	cin >> n >> m;
	get_prim ();	
	ll res = 0, mul = 1, all = 1, last = 1;
	for (int i = 1; i <= n; ++i) {
		all = (all * (m % mod)) % mod;
		auto [fi, se] = prim.front ();
		if (i == se) last = fi, prim.pop ();
		mul = (mul * (m / last % mod)) % mod;
		res = (res + all - mul) % mod;
		res = ((res % mod) + mod) % mod;
	}
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}