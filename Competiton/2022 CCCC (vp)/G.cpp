#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m, q;

void init () {}

void charming () {
	init ();
	cin>> n >> m >> q;
	vector <vector <int> > safe (n + 5, vector <int> (m + 5, 1));
	for (int i = 1, opt, x; i <= q; ++i) {
		cin >> opt >> x;
		if (opt == 0) for (int j = 1; j <= m; ++j) safe[x][j] = 0;
		else for (int j = 1; j <= n; ++j) safe[j][x] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	ans += safe[i][j];
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}