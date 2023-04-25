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
	string opt;
	vector <int> a (n + 5), bel (n + 5);
	cin >> opt, opt = '#' + opt;
	for (int i = 1; i <= n; ++i)
	a[i] = a[i - 1] + (opt[i] == '+' ? 1 : -1);
	int len = sqrt (n) + 5, blo = (n - 1 + len) / len;
	vector <pair <int, int> > f (blo + 5);
	for (int i = 1, be, en, mn, mx; i <= blo; ++i) {
		be = (i - 1) * len + 1, en = min (n, be + len - 1);
		mn = INT_MAX, mx = -INT_MAX;
		for (int j = be; j <= en; ++j) {
			mn = min (mn, a[j]);
			mx = max (mx, a[j]);
			bel[j] = i;
		}
		f[i].first = mn, f[i].second = mx;
	}
	for (int i = 1, l, r, extra, mn, mx; i <= m; ++i) {
		cin >> l >> r;
		extra = a[r] - a[l - 1];
		int cur_blo1 = bel[l], cur_blo2 = bel[r];
		mn = 0, mx = 0, --l, ++r;
		for (int j = 1; j < cur_blo1; ++j)
		mn = min (mn, f[j].first), mx = max (mx, f[j].second);
		for (int j = max (1ll, (cur_blo1 - 1) * len + 1); j <= l; ++j)
		mn = min (mn, a[j]), mx = max (mx, a[j]);
		for (int j = cur_blo2 + 1; j <= blo; ++j)
		mn = min (mn, f[j].first - extra), mx = max (mx, f[j].second - extra);
		for (int j = r; j <= min (n, cur_blo2 * len); ++j)
		mn = min (mn, a[j] - extra), mx = max (mx, a[j] - extra);
		cout << mx - mn + 1 << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}