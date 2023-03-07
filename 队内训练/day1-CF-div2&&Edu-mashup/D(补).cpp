#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i)
	cin >> a[i];
	// c1 = 1, c2 = 1;
	int res = INT_MAX, cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (!(a[i] % 3)) cur = max (cur, a[i] / 3 - 1);
		else cur = max (cur, a[i] / 3);
	}
	res = min (res, 2 + cur);
	// c1 = 0, c2 = 2;
	cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] <= 1) {
			cur = INT_MAX;
			break;
		}
		if (a[i] % 3 == 1) cur = max (cur, (a[i] - 2) / 3);
		else cur = max (cur, a[i] / 3);
	}
	res = min (res, 2 + cur);
	// c1 = 2, c2 = 0;
	cur = 0;
	for (int i = 1; i <= n; ++i) {
		cur = max (cur, a[i] / 3);
	}
	res = min (res, 2 + cur);
	// c1 = 1, c2 = 0;
	cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] % 3 == 2) {
			cur = INT_MAX;
			break;
		}
		else cur = max (cur, a[i] / 3);
	}
	res = min (res, 1 + cur);
	// c1 = 0, c2 = 1;
	cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] % 3 == 1) {
			cur = INT_MAX;
			break;
		}
		else cur = max (cur, a[i] / 3);
	}
	res = min (res, 1 + cur);
	// c1 = 0, c2 = 0;
	cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] % 3) {
			cur = INT_MAX;
			break;
		}
		cur = max (cur, a[i] / 3);
	}
	res = min (res, cur);
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}