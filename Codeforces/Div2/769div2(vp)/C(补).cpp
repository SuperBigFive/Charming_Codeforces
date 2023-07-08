#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, a, b;

void init () {}

void charming () {
	init ();
	cin >> a >> b;
	int res = b - a;
	for (int i = a, nb; i <= b; ++i) {
		nb = 0;
		for (int j = 30; j >= 0; --j) {
			int fi = ((i >> j) & 1);
			int se = ((b >> j) & 1);
			if (fi | se) nb += (1 << j);
			if (fi == 1 && se == 0) break;
		}
		res = min (res, i + (i | nb) + 1 - a - b);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}