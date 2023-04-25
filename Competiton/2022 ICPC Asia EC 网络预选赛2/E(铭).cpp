#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

void init () {}

void charming () {
	ll n, k;
	cin >> n >> k;
	if (k & 1) {
		ll res = k + (n - 1) / 2 * 5 + ((n - 1) & 1) * 2;
		cout << res << endl;
	}
	else {
		ll res = k;
		while (!(k & 1)) k >>= 1;
		int nxt = 3;
		while (!(k % nxt)) nxt += 2;
		res = res + nxt + (n - 2) / 2 * 5 + ((n - 2) & 1) * 2;
		cout << res << endl;
	}
}

signed main () {
	charming ();
	return 0;	
}