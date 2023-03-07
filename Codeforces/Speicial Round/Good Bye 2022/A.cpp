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
	vector <int> a (n), b (m);
	for (auto &it : a) cin >> it;
	for (auto &it : b) cin >> it;
	ll res = 0;
	for (int i = 0; i < m; ++i) {
		int id = 0, mn = INT_MAX;
		for (int j = 0; j < n; ++j) {
			if (a[j] < mn) {
				mn = a[j];
				id = j;
			}
		}
		a[id] = b[i];
	}
	for (int i = 0; i < n; ++i) {
		res += a[i];
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}