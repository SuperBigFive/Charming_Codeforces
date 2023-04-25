#include <bits/stdc++.h>
#define ll long long
#define int ll
#define fi first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

pair <int, int> d[3];

void init () {}

int solve1 (int h) {
	int l = 1, r = LLONG_MAX / 10 - 1, res = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (r - l <= 10) {
			mid = l;
			while ((__int128)(d[0].fi - d[2].se) * (mid / d[0].se) + 
		(d[1].fi - d[2].se) * (mid / d[1].se) < h) ++mid;
			return mid;
		}
		if ((__int128)(d[0].fi - d[2].se) * (mid / d[0].se) + 
		(d[1].fi - d[2].se) * (mid / d[1].se) >= h)
		r = mid - 1, res = mid;
		else l = mid + 1;
	}
	return res;
}

void solve2 () {
	int dam = d[0].fi + d[1].fi - d[2].se;
	int times = (d[2].fi - 1) / dam + 1;
	int res = times * d[1].se;
	for (int i = 1; i <= times; ++i)
	res = min (res, res - i * d[1].se + solve1 (d[2].fi - dam * (times - i)));
	cout << res << endl; 
}

void charming () {
	init ();
	for (int i = 0; i < 3; ++i) {
		cin >> d[i].fi >> d[i].se;
	}
	if (d[0].se > d[1].se)
	swap (d[0], d[1]);
	if (d[0].se == d[1].se) {
		cout << ((d[2].fi - 1) / (d[0].fi + d[1].fi
		- d[2].se) + 1) * d[0].se << endl;
	}
	else solve2 ();
	/*
	else {
		double c1 = (double) d[2].se / (d[1].se - d[0].se);
		double c2 = (double) (d[1].se - d[0].se) 
		* (d[0].fi - d[2].se) / d[0].se;
		if (c1 <= c2) cout << solve1 (d[2].first) << endl;
		else solve2 ();
	}*/
}

signed main () {
	charming ();
	return 0;
}