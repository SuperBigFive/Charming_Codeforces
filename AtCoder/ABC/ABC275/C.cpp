#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

char mp[15][15];
set <pair <int, int> > s;

void init () {}

bool check (int nx1, int ny1, int nx2, int ny2) {
	if (s.count (make_pair (nx1, ny1))
	&& s.count (make_pair (nx2, ny2))) return true;
	return false;
}

void charming () {
	init ();
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			cin >> mp[i][j];
			if (mp[i][j] == '#')
			s.insert (make_pair (i, j));
		}
	}
	int res = 0;
	for (auto [x1, y1] : s) {
		for (auto [x2, y2] : s) {
			if (x1 == x2 && y1 == y2) continue;
			int dx = x2 - x1, dy = y2 - y1;
			int nx1, nx2, ny1, ny2;
			nx1 = x1 - dy, ny1 = y1 + dx;
			nx2 = x2 - dy, ny2 = y2 + dx;
			if (check (nx1, ny1, nx2, ny2)) ++res;
		}
	}
	cout << res / 4 << endl;
}

signed main () {
	charming ();
	return 0;
}