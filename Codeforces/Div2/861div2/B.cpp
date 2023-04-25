#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <int> > a (n + 5, vector <int> (m + 5));
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	cin >> a[i][j];
	ll res = 0;
	for (int i = 1; i <= m; ++i) {
		vector <int> b, pre (n + 5);
		for (int j = 1; j <= n; ++j)
		b.emplace_back (a[j][i]);
		sort (b.begin (), b.end ());
		for (int j = 1; j <= n; ++j)
		pre[j] = pre[j - 1] + b[j - 1];
		for (int j = 1; j < n; ++j)
		res += (pre[n] - pre[j]) - (b[j - 1] * (n - j));
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}