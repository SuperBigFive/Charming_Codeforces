#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;

void init () {}

void charming () {
	init ();
	array <int, 6> arr;
	ll res1 = 1, res2 = 1;
	for (int i = 0; i < 6; ++i) {
		cin >> arr[i];
		if (i < 3) res1 = (res1 * (arr[i] % mod)) % mod;
		else res2 = (res2 * (arr[i] % mod)) % mod;
	}
	ll res = (res1 - res2) % mod;
	res = ((res + mod) % mod);
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}