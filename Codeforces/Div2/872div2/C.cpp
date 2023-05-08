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
	vector <int> x;
	int sitLeft = 0, sitRight = 0;
	for (int i = 1, a; i <= n; ++i) {
		cin >> a;
		if (a == -1) ++sitLeft;
		else if (a == -2) ++sitRight;
		else x.emplace_back (a);
	}
	sort (x.begin (), x.end ());
	x.resize (unique (x.begin (), x.end ()) - x.begin ());
	int ans = min (m, max (sitLeft, sitRight) + (int) x.size ());
	for (int i = 0, siz = x.size (); i < siz; ++i) {
		ans = max (ans, 1 + min (x[i] - 1, sitLeft + i) + min (m - x[i], sitRight + siz - i - 1));
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}