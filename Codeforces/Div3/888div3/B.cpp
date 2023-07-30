#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5), b, c, d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] & 1) b.emplace_back (a[i]);
		else c.emplace_back (a[i]);
	}
	sort (b.begin (), b.end ());
	sort (c.begin (), c.end ());
	for (int i = 1, p = 0, q = 0; i <= n; ++i) {
		if (a[i] & 1) d.emplace_back (b[p++]);
		else d.emplace_back (c[q++]);
	}
	vector <int> e = d;
	sort (e.begin (), e.end ());
	if (e == d) cout << "Yes" << endl;
	else cout << "No" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}