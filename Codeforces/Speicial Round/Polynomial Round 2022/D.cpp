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
	vector <vector <int> > a (n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		a[i].resize (m + 1);
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 1) ++cnt;
		}
	}
	if (cnt % n) {
		cout << "-1" << endl;
		return;
	}
	int ave = cnt / n;
	vector <int> need_num (n + 1), num1 (n + 1);
	vector <set <int> > need_pos (m + 1);
	for (int i = 1, c; i <= n; ++i) {
		c = 0;
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == 1) ++c;
		}
		if (c < ave) {
			need_num[i] = ave - c;
			for (int j = 1; j <= m; ++j) {
				if (!a[i][j]) need_pos[j].insert (i);
			}
		}
		num1[i] = c;
	}
	vector <array <int, 3> > ans;
	array <int, 3> d;
	for (int i = 1; i <= n; ++i) {
		if (num1[i] <= ave) continue;
		for (int j = 1; j <= m && num1[i] > ave; ++j) {
			if (!a[i][j])	continue;
			int del = -1;
			for (auto it : need_pos[j]) {
				d[0] = i, d[1] = it, d[2] = j;
				ans.emplace_back (d);
				del = it;
				break;
			}
			if (del == -1) continue;
			--num1[i];
			need_pos[j].erase (del);
			--need_num[del];
			if (need_num[del] <= 0) {
				for (int k = 1; k <= m; ++k) {
					need_pos[k].erase (del);
				}
			}
		}
	}
	cout << ans.size () << endl;
	for (auto [x, y, z] : ans) {
		cout << x << " " << y << " " << z << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}