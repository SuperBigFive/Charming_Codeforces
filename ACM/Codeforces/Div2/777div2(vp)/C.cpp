#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <char> > mp (n + 1);
	for (int i = 1; i <= n; ++i) {
		mp[i].resize (m + 1);
		for (int j = 1; j <= m; ++j)
		cin >> mp[i][j];
	}
	if (mp[1][1] == '1') {
		cout << "-1" << endl;
		return;
	}
	vector <array <int, 4> > ans;
	array <int, 4> a;
	for (int i = n - 1; i >= 1; --i) {
		for (int j = m; j >= 1; --j) {
			if (mp[i + 1][j] == '1') {
				a[0] = i, a[1] = j;
				a[2] = i + 1, a[3] = j;
				ans.emplace_back (a);
			}
		}
	}
	for (int i = m; i > 1; --i) {
		if (mp[1][i] == '1') {
			a[0] = 1, a[1] = i - 1;
			a[2] = 1, a[3] = i;
			ans.emplace_back (a);
		}
	}
	cout << ans.size () << endl;
	for (auto &[x1, y1, x2, y2] : ans) {
		cout << x1 << " " << y1 << " "
		<< x2 << " " << y2 << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}