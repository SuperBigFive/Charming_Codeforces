#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, a, b, da, db;

void init () {}

void charming () {
	init ();
	cin >> n >> a >> b >> da >> db;
	vector <int> fa (n + 1), dep (n + 1), dp (n + 1);
	vector <vector <int> > adj (n + 1);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	int mx = 0;
	auto dfs = [&] (auto && me, int f, int u, int d) -> void {
		fa[u] = f, dep[u] = d;
		vector <int> vec;
		if (adj[u].size () == 1 && u != 1) {
			dp[u] = 1;
			return;
		}
		for (auto &v : adj[u]) {
			if (v == f) continue;
			me (me, u, v, d + 1);
			dp[u] = max (dp[u], dp[v] + 1);
			vec.emplace_back (dp[v]);
		}
		vec.emplace_back (0);
		sort (vec.begin (), vec.end (), greater <int> ());
		mx = max (mx, vec[0] + vec[1] + 1);
	};
	dfs (dfs, 0, 1, 0);
	int u = a, v = b;
	if (dep[u] < dep[v]) swap (u, v);
	while (dep[u] > dep[v]) u = fa[u];
	while (u != v) u = fa[u], v = fa[v];
	if (dep[a] + dep[b] - 2 * dep[u] <= da
	|| mx <= 2 * da + 1 || db < 2 * da + 1) {
		cout << "Alice" << endl;
	}
	else cout << "Bob" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}