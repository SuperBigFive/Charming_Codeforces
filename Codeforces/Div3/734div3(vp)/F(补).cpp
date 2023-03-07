#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e3 + 5;
const int mod = 1e9 + 7;

int t, n, k;

ll add (ll x, ll y) {return (x + y) % mod;}
ll mul (ll x, ll y) {return x * y % mod;}

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <vector <int> > adj (n + 1);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	if (k == 2) return (void) (cout << n * (n - 1) / 2 << endl);
	vector <int> dep (n + 1), cnt_tmp (n + 1);
	vector <vector <int> > cnt;
	auto dfs = [&] (auto && me, int f, int u, int d) -> void {
		dep[u] = d, ++cnt_tmp[d];
		for (auto &v : adj[u]) {
			if (v == f) continue;
			me (me, u, v, d + 1);
			if (f == 0) {
				cnt.emplace_back (cnt_tmp);
				cnt_tmp.clear ();
				cnt_tmp.resize (n + 1, 0);
			}
		}
	};
	ll res = 0;
	for (int i = 1, m; i <= n; ++i) {
		m = adj[i].size ();
		if (m < k) continue;
		cnt.resize (1, vector <int> (n + 1, 0));
		dfs (dfs, 0, i, 0);
		for (int j = 1, ok = 1; j < n && ok; ++j) {
			vector <vector <int> > dp (m + 5, vector <int> (k + 5, 0));
			dp[0][0] = 1;
			for (int p = 1; p <= m; ++p) {
				dp[p][0] = 1;
				for (int q = 1; q <= k; ++q) {
					dp[p][q] = add (dp[p][q], dp[p - 1][q]);
					dp[p][q] = add (dp[p][q], mul (dp[p - 1][q - 1], cnt[p][j]));
				}
			}
			res = add (res, dp[m][k]);
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}