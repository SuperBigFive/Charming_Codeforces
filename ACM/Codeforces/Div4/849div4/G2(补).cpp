#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, c;

void init () {}

void charming () {
	init ();
	cin >> n >> c;
	vector <int> a (n + 5), pre (n + 5);
	vector <pair <int, int> > b;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b.emplace_back (make_pair (a[i] + min (i, n - i + 1), i));
	}
	sort (b.begin (), b.end (), [] (pair <int, int> &x,
	pair <int, int> &y) {
		if (x.first != y.first) return x.first < y.first;
		return x.second < y.second;
	});
	set <int> vis;
	int mx = 0, ok = false, old_c = c;
	for (int i = 1; i <= n; ++i) {
		if (c >= b[i - 1].first) {
			++mx, c -= b[i - 1].first;
			if (b[i - 1].second <= (n - 1) / 2 + 1) ok = true;
			vis.insert (b[i - 1].second);
		}
		pre[i] = pre[i - 1] + b[i - 1].first;
	}
	if (ok) return void (cout << mx << endl);
	int res = 0;
	for (int i = 1, d, l, r, k; i <= n; ++i) {
		d = old_c - (a[i] + i);
		if (d < 0 || vis.count (i)) continue;
		l = 0, r = n, k = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if (pre[mid] <= d) l = mid + 1, k = mid;
			else r = mid - 1;
		}
		res = max (res, k + 1);
	}
	for (int i = 1, d, l, r, k; i <= mx; ++i) {
		d = old_c - (a[b[i - 1].second] + b[i - 1].second);
		if (d < 0) continue;
		if (pre[i - 1] <= d) {
			d -= pre[i - 1];
			l = i, r = mx, k = i;
			while (l <= r) {
				int mid = l + r >> 1;
				if (pre[mid] - pre[i] <= d) l = mid + 1, k = mid;
				else r = mid - 1;
			}
			res = max (res, k);
		}
		else {
			l = 0, r = i - 1, k = 0;
			while (l <= r) {
				int mid = l + r >> 1;
				if (pre[mid] <= d) l = mid + 1, k = mid;
				else r = mid - 1;
			}
			res = max (res, k + 1);
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}