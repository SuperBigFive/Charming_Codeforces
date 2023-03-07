#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m, d;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> d;
	vector <int> p (n + 5), a (m + 5), pos (n + 5);
	for (int i = 1; i <= n; ++i) cin >> p[i], pos[p[i]] = i;
	for (int i = 1; i <= m; ++i) cin >> a[i];
	int res = INT_MAX;
	for (int i = 1; i < m; ++i) {
		if (pos[a[i]] < pos[a[i + 1]] && 
		pos[a[i + 1]] <= pos[a[i]] + d) {
			res = min (res, pos[a[i + 1]] - pos[a[i]]);
			if (d < n - 1) res = min (res, d - (pos[a[i + 1]] - pos[a[i]]) + 1);
		}
		else res = 0;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}