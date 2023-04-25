#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e5 + 5;
mt19937 rnd (random_device {}());

int t, n, q;

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	vector <double> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += i * 1e-6;
	++n;
	auto force = [&] () -> int {
		int mx1 = -INT_MAX, mx2 = -INT_MAX;
		for (int i = 1, tmp1, tmp2; i <= n; ++i) {
			tmp1 = mx1, tmp2 = mx2;
			mx1 = max ({mx1, (int) floor (a[i]) + (int) floor (tmp2), (int) floor (a[i])});
			if (tmp1) mx2 = max (mx2, (int) floor (tmp1) - (int) floor (a[i]));
		}
		return mx1;
	};
	int mx1 = force ();
	cout << mx1 << endl;
	auto modify = [&] (int id, double v) -> void {
		int al = floor (a[id - 1]), ar = floor (a[id + 1]), aid = floor (a[id]);
		int val = floor (v);
		if (a[id] > a[id - 1] && a[id] > a[id + 1]) {
			if (v > max (a[id - 1], a[id + 1])) mx1 += val - aid;
			else if (v < min (a[id - 1], a[id + 1])) mx1 += al + ar - aid - val;
			else mx1 -= aid - max (al, ar);
		}
		else if (a[id] < a[id - 1] && a[id] < a[id + 1]) {
			if (v > max (a[id - 1], a[id + 1])) mx1 += aid - al + val - ar;
			else if (v < min (a[id - 1], a[id + 1])) mx1 += aid - val;
			else mx1 -= min (al, ar) - aid;
		}
		else if (a[id] > a[id - 1] && a[id] < a[id + 1]) {
			if (v > a[id + 1]) mx1 += val - ar;
			else if (v < a[id - 1]) mx1 += al - val;
		}
		else {
			if (v < a[id + 1]) mx1 += ar - val;
			else if (v > a[id - 1]) mx1 += val - al;
		}
		a[id] = v;
	};
	for (int i = 1, l, r; i <= q; ++i) {
		cin >> l >> r;
		if (l > r) swap (l, r);
		double tmpl = a[l], tmpr = a[r];
		modify (l, floor (tmpr) + l * 1e-6);
		modify (r, floor (tmpl) + r * 1e-6);
		cout << mx1 << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}