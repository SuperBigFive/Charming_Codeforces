#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

ll t, n, siz;
vector <ll> pn;

void init () {}

void get_pn () {
	for (int i = 3, r = 2; r <= 1e12; ++i) {
		r = i * r;
		pn.emplace_back (r);
	}
	siz = pn.size ();
}

int get_ones (ll num) {
	int res = 0;
	while (num) {
		ll x = num & -num;
		if (x) ++res, num -= x;
		else break;
	}
	return res;
}

void charming () {
	init ();
	cin >> n;
	ll res = get_ones (n);
	for (int i = 1; i < (1 << siz); ++i) {
		ll tmp = 0, cnt = 0;
		for (int j = 0; j < siz; ++j) {
			if ((i >> j) & 1) tmp += pn[j], ++cnt;
			if (tmp > n) break;
			res = min (res, cnt + get_ones (n - tmp));
		}
	}
	cout << res << endl;
}

signed main () {
	get_pn ();
	cin >> t;
	while (t--) charming ();
	return 0;
}