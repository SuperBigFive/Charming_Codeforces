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
	for (int i = 0; i <= n; ++i) {
		int bad = 0, good = 0;
		for (int j = 1; j <= n; ++j) {
			if (a[j] <= i) ++good;
			else ++bad;
		}
		if (bad == i) return void (cout << i << endl);
	}
	cout << -1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}