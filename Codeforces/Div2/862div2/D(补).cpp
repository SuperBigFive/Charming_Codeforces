#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, rt1, rt2;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> dep1 (n + 5), dep2 (n + 5);
	vector <vector <int> > adj (n + 5);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	
	auto dfs = [&] (auto && me, vector <int> &dep, int f, int u, int d) -> void {
		dep[u] = d;
		for (auto &v : adj[u]) {
			if (v == f) continue;
			me (me, dep, u, v, d + 1);
		}
	};
	
	dfs (dfs, dep1, 0, 1, 1);
	for (int i = 1; i <= n; ++i) if (dep1[rt1] < dep1[i]) rt1 = i;
	dfs (dfs, dep1, 0, rt1, 1);
	for (int i = 1; i <= n; ++i) if (dep1[rt2] < dep1[i]) rt2 = i;
	dfs (dfs, dep2, 0, rt2, 1);
	vector <int> ans (n + 5, n), tag (n + 5);
	for (int i = 1; i <= n; ++i) 
	++tag[max (dep1[i], dep2[i]) - 1];
	--tag[dep2[rt1] - 1];
	int cur = 0;
	for (int i = n; i >= 1; --i) {
		cur += tag[i];
		ans[i] = n - cur;
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

signed main () {
	charming ();
	return 0;
}