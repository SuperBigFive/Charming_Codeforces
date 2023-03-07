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
	vector <int> a (n), b(n);
	for (auto &it : a) cin >> it;
	int mx1 = 0, mx2 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		if (a[i] > b[i]) swap (a[i], b[i]);
		mx1 = max (a[i], mx1);
		mx2 = max (b[i], mx2);
	}
	cout << mx2 * mx1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}