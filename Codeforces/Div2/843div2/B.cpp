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
	vector <vector <int> > c (n + 5);
	map <int, int> cnt;
	for (int i = 1, k; i <= n; ++i) {
		cin >> k;
		c[i].resize (k + 5);
		for (int j = 1; j <= k; ++j) {
			cin >> c[i][j];
			++cnt[c[i][j]];
		}
	}
	for (int i = 1; i <= n; ++i) {
		bool ok = true;
		for (int j = 1; j < c[i].size (); ++j) {
			--cnt[c[i][j]];
			if (!cnt[c[i][j]]) ok = false;
		}
		if (ok) {cout << "YES" << endl; return;}
		for (int j = 1; j < c[i].size (); ++j) {
			++cnt[c[i][j]];
		}
	}
	cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}