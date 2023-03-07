#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, l;

void init () {}

void charming () {
	init ();
	cin >> n >> l;
	vector <int> cnt (l);
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		for (int j = 0; j < l; ++j) {
			if ((x >> j) & 1) ++cnt[j];
		}
	}
	int y = 0;
	for (int i = 0; i < l; ++i) if (cnt[i] >= (n - 1) / 2 + 1) {
		y += 1 << i;
	}
	cout << y << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}