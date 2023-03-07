#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m, r, c;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> r >> c;
	vector <string> mp (n + 1);
	bool ok = false;
	for (int i = 1; i <= n; ++i) {
		cin >> mp[i];
		mp[i] = '#' + mp[i];
		for (auto &it : mp[i]) if (it == 'B') {
			ok = true;
		}
	}
	if (!ok) {
		cout << -1 << endl;
		return;
	}
	if (mp[r][c] == 'B') {
		cout << 0 << endl;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (mp[i][c] == 'B') {
			cout << 1 << endl;
			return;
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (mp[r][i] == 'B') {
			 cout << 1 << endl;
			 return;
		}
	}
	cout << 2 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}