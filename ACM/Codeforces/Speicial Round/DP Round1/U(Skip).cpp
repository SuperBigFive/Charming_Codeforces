#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <pair <int, int> > blo (m);
	for (auto &it : blo) cin >> it.first >> it.second;
	sort (blo.begin (), blo.end (), [] (pair <int, int> &x,
	pair <int, int> &y) {return x.second < y.second;});
	int st = 0, last_r = 0, last_c = blo[0].second;
	map <pair <int, int>, int> vis;
	for (int i = 0; i < m; ++i) {
		if (blo[i].first != last_r) {
			if (st == 1 && ((blo[i].second - last_c) & 1)) {
				cout << "NO" << endl;
				return;
			}
		}
		else {
			if (st == 1 && (!((blo[i].second - last_c) & 1))) {
				cout << "NO" << endl;
				return;
			}
		}
		if (st == 0) {
			vis[make_pair (1 + ((blo[i].first - 1) ^ 1), blo[i].second)] = 1;
			vis[make_pair (1 + ((blo[i].first - 1) ^ 1), blo[i].second + 1)] = 1;
		}
		else {
			vis[make_pair (1 + ((blo[i].first - 1) ^ 1), blo[i].second)] = 1;
			vis[make_pair (1 + ((blo[i].first - 1) ^ 1), blo[i].second - 1)] = 1;
		}
		st ^= 1;
		last_r = blo[i].first, last_c = blo[i].second;
	}
	for (int i = 0; i < m; ++i) {
		if (vis.count (blo[i])) {
			cout << "NO" << endl;
			return;
		}
	}
	if (st) cout << "NO" << endl;
	else cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}