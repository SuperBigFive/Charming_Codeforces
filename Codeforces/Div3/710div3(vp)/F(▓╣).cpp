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
	vector <pair <int, int> > p (n);
	for (auto &it : p) cin >> it.first;
	for (auto &it : p) cin >> it.second;
	map <pair <int, int>, bool> vis;
	int cx = 1, cy = 1, res = 0;
	sort (p.begin (), p.end ());
	for (auto &[x, y] : p) {
		vis[make_pair (cx, cy)] = true;
		if (vis.count (make_pair (x, y))) continue;
		int cst = (cx + cy) & 1, nst = (x + y) & 1;
		if (cst == 0 && nst == 0) {
			if (cx - cy == x - y) res += x - cx;
			else res += ((x - y) - (cx - cy)) / 2;
		}
		else if (cst == 0 && nst == 1) {
			res += ((x - y) - (cx + 1 - cy)) / 2;
		}
		else if (cst == 1 && nst == 0) {
			res += ((x - y) - (cx - 1 - cy)) / 2;
		}
		else {
			res += ((x - y) - (cx - cy)) / 2;
		}
		cx = x, cy = y;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}