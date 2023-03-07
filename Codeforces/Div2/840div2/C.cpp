#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	int sum = 0;
	for (auto &it : a) cin >> it, sum += it;
	int res = sum;
	if (n == 2) {
		if (a[0] > a[1]) swap (a[0], a[1]);
		cout << max (a[0] + a[1], 2 * (a[1] - a[0])) << endl;
		return;
	}
	else if (n == 3) {
		if (a[0] >= a[1] && a[0] >= a[2]) {
			cout << 3 * a[0] << endl;
			return;
		}
		else if (a[2] >= a[0] && a[2] >= a[1]) {
			cout << 3 * a[2] << endl;
			return;
		}
		else {
			if (a[0] > a[2]) swap (a[0], a[2]);
			res = max (res, 3 * a[2]);
			res = max (res, 3 * (a[1] - a[0]));
			cout << res << endl;
			return;
		}
	}
	else {
		int mx = 0, mx1 = 0, mx2 = 0;
		for (int i = 0; i < n; ++i) {
			if (i != 1 && i != n - 2) mx = max (mx, a[i]);
			mx1 = max (mx1, abs (a[1] - a[i]));
			mx2 = max (mx2, abs (a[n - 2] - a[i]));
		}
		res = max (res, mx1 * n);
		res = max (res, mx2 * n);
		res = max (res, mx * n);
		res = max (res, a[1] * n);
		res = max (res, a[n - 2] * n);
		res = max (res, a[1] * (n - 2) + max (a[0] + a[1], 2 * abs (a[1] - a[0])));
		res = max (res, a[n - 2] * (n - 2) + max (a[n - 2] + a[n - 1], 2 * abs (a[n - 2] - a[n - 1])));
		cout << res << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}