#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e3 + 5;

int n, m, k;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> k;
	vector <pair <int, int> > p1, p2;
	vector <string> mp (n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> mp[i], mp[i] = '#' + mp[i];
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) {
			if ((i - 1) * m + j <= k && mp[i][j] == '0') 
			p1.emplace_back (make_pair (i, j));
			if ((i - 1) * m + j > k && mp[i][j] == '1')
			p2.emplace_back (make_pair (i, j));
		}
	}
	int res = 0, siz = p1.size ();
	for (int i = 0; i < siz; ++i) {
		auto [x1, y1] = p1[i];
		auto [x2, y2] = p2[i];
		res += abs (x1 - x2) + abs (y1 - y2);
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}