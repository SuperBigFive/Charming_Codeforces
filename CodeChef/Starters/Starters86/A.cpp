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
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int ans = LLONG_MAX;
	for (int i = 1, nans; i <= n; ++i) {
		nans = 0;
		if (i - 1 >= 1) nans= max (nans, abs (a[i] - a[i - 1]));
		if (i + 1 <= n) nans = max (nans, abs (a[i] - a[i + 1]));
		ans = min (ans, nans);
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}