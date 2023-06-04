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
	vector <vector <int> > lamp (n + 5);
	for (int i = 1, a, b; i <= n; ++i) {
		cin >> a >> b;
		lamp[a].emplace_back (b);
	}
	int ans = 0;
	for (int i = 1, siz; i <= n; ++i) {
		sort (lamp[i].begin (), lamp[i].end ());
		reverse (lamp[i].begin (), lamp[i].end ());
		siz = lamp[i].size ();
		for (int j = 0; j < min (siz, i); ++j) ans += lamp[i][j];
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}