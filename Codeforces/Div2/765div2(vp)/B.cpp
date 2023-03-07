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
	vector <vector <int> > pos (N);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]].emplace_back (i);
	}
	int res = -1;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < (int) pos[i].size () - 1; ++j) {
			res = max (res, pos[i][j] + n - pos[i][j + 1]);
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}