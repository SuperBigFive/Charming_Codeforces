#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;	
	vector <int> a (n), b (n);
	vector <pair <int, int> > ans (n);
	vector <pair <int, pair <int, int> > > seq;
	int bal = 0, all_mx = 0, all_mn = 0;
	for (int i = 0, mx, mn; i < n; ++i) {
		cin >> a[i] >> b[i];
		bal += a[i] - b[i];
		mn = a[i] >= m ? m : a[i];
		mx = b[i] >= m ? m : b[i];
		seq.emplace_back (make_pair (i, make_pair (mn, mx)));
		all_mx += mx * 2 - m;
		all_mn += m - mn * 2;
	}
	int res;
	if (bal + all_mx >= 0 && bal + all_mn <= 0) {
		res = 0;
		int diff = (bal + all_mx) / 2;
		for (int i = 0, old, dec; i < n; ++i) {
			old = seq[i].second.second;
			dec = min (old, diff);
			dec = min (dec, a[i] - m + old);
			diff -= dec;
			ans[i].second = old - dec;
			ans[i].first = m - ans[i].second;
			res += a[i] - ans[i].first;
			res -= b[i] - ans[i].second;
		}
		res = abs (res);
	}
	else if (bal + all_mn > 0) {
		res = abs (bal + all_mn);
		for (int i = 0; i < n; ++i) {
			ans[i].first = seq[i].second.first;
			ans[i].second = m - ans[i].first;
		}
	}
	else {
		res = abs (bal + all_mx);
		for (int i = 0; i < n; ++i) {
			ans[i].second = seq[i].second.second;
			ans[i].first = m - ans[i].second;
		}
	}
	cout << res << endl;
	for (auto [x, y] : ans) {
		cout << x << " " << y << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}