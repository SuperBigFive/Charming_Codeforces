#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <int> > cx (maxn), cy (maxn);
	vector <vector <int> > color (n + 1);
	set <int> c;
	for (int i = 1; i <= n; ++i) {
		color[i].resize (m + 1);
		for (int j = 1; j <= m; ++j) {
			cin >> color[i][j];
			c.insert (color[i][j]);
			cx[color[i][j]].emplace_back (i);
			cy[color[i][j]].emplace_back (j);
		}
	}
	ll res = 0;
	for (auto &it : c) {
		ll sumx = 0, sumy = 0, resx = 0, resy = 0;
		sort (cx[it].begin (), cx[it].end ());
		sort (cy[it].begin (), cy[it].end ());
		for (auto &x : cx[it]) sumx += x;
		for (auto &y : cy[it]) sumy += y;
		for (int i = 0, siz = cx[it].size (); i < siz; ++i) {
			resx += (sumx -= cx[it][i]) - 
			(cx[it].size () - i - 1) * cx[it][i];
			resy += (sumy -= cy[it][i]) - 
			(cy[it].size () - i - 1) * cy[it][i];
		}
		res += resx + resy;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}