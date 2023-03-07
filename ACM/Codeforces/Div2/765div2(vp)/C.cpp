#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e4 + 5;

int n, l, k;

void init () {}

void charming () {
	init ();
	cin >> n >> l >> k;
	vector <int> d (n), a (n);
	vector <vector <vector <int> > > dp (2, 
	vector <vector <int> > (k + 5, vector <int> (n + 5, INT_MAX)));
	for (auto &it : d) cin >> it;
	for (auto &it : a) cin >> it;
	d.emplace_back (l), a.emplace_back (0);
	vector <int> b = a;
	b.pop_back ();
	sort (b.begin (), b.end ());
	int m = unique (b.begin (), b.end ()) - b.begin ();
	vector <int> c, rev (N);
	for (int i = 0; i < m; ++i) {
		c.emplace_back (b[i]);
		rev[b[i]] = i;
	}
	dp[0][0][rev[a[0]]] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int s_id = 0; s_id < m; ++s_id) {
				if (dp[i & 1][j][s_id] >= INT_MAX) continue;
				if (i > 0) dp[(i + 1) & 1][j + 1][s_id] = 
				min (dp[(i + 1) & 1][j + 1][s_id], 
				dp[i & 1][j][s_id] + c[s_id] * (d[i + 1] - d[i]));
				dp[(i + 1) & 1][j][rev[a[i]]] = min (dp[(i + 1) & 1][j][rev[a[i]]],
				dp[i & 1][j][s_id] + a[i] * (d[i + 1] - d[i]));
			}
		}
		for (int j = 0; j <= k; ++j) {
			for (int s_id = 0; s_id < m; ++s_id) {
				dp[i & 1][j][s_id] = INT_MAX;
			}
		}
	}
	int res = INT_MAX;
	for (int j = 0; j <= k; ++j) {
		for (int s_id = 0; s_id < m; ++s_id) {
			res = min (res, dp[n & 1][j][s_id]);
		}
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}