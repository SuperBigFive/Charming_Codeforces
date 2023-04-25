#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

bool check (int l, vector <vector <int> > &a) {
	vector <vector <int> > tag (2 * n + 5);
	vector <int> val (m + 5);
	for (int i = 0; i < 2 * n + 5; ++i)
	tag[i].emplace_back (1 - l);
	for (int i = n + 1, r, c; i <= n + n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i - n][j] < l) {
				r = i - l + 1;
				c = j - l + 1;
				if (tag[r].back () != c)
				tag[r].emplace_back (c);
			}
		}
	}
	for (int i = 0; i < 2 * n + 5; ++i) 
	tag[i].emplace_back (m - l + 2);
	for (int r = 1; r <= n + n - l + 1; ++r) {
		vector <int> no_choice;
		for (int i = 0; i < tag[r].size () - 1; ++i) {
			if (tag[r][i] + l < tag[r][i + 1]) {
				for (int j = max (1ll, tag[r][i] + l); j < tag[r][i + 1]; ++j)
				no_choice.emplace_back (j);
			}
		}
		for (int i = 1, p = 0; i <= m - l + 1; ++i) {
			if (p < no_choice.size () && i == no_choice[p]) {
				--val[i], ++p;
				if (val[i] <= 0 && r >= n + 1) return true;
			}
			else val[i] = l;
		}
	}
	return false;
}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <int> > a (n + 5);
	for (int i = 0; i < n + 5; ++i)
	a[i].resize (m + 5);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	int l = 1, r = min (n, m), res = 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid, a)) l = mid + 1, res = mid;
		else r = mid - 1;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}