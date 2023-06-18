#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	string l, r;
	cin >> l >> r;
	n = l.size (), m = r.size ();
	int ans = 0;
	if (n != m) ans = r[0] - '0' + (m - 1) * 9;
	else {
		int p = 0;
		while (p < m && l[p] == r[p]) ++p;
		if (p < m) {
			ans += abs (r[p] - l[p]);
			ans += 9 * (m - p - 1);
		}
	}
	int nans = 0;
	while (l.size () < r.size ()) l = '0' + l;
	for (int i = 0; i < m; ++i) nans += abs (l[i] - r[i]);
	ans = max (ans, nans);
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}