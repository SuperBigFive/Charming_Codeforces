#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m, tot, scc_cnt;

void init () {tot = scc_cnt = 0;}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <int> > adj (n + 1);
	map <pair <int, int>, bool > edge;
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		edge[{u, v}] = true;
	}
	vector <int> stk, ok (n + 1), bel (n + 1);
	vector <int> dfn (n + 1), low (n + 1);
	vector <vector <int> > scc;
	auto dfs1 = [&] (auto && me, int u) -> void {
		dfn[u] = low[u] = ++tot;
		stk.emplace_back (u);
		for (auto &v : adj[u]) {
			if (!dfn[v]) {
				me (me, v);
				low[u] = min (low[u], low[v]);
				continue;
			}
			else if (!bel[v]) low[u] = min (low[u], dfn[v]);
			ok[v] = true;
		}
		if (low[u] >= dfn[u]) {
			scc.emplace_back (vector <int> ());
			while (true) {
				scc[scc_cnt].emplace_back (stk.back ());
				stk.pop_back ();
				bel[scc[scc_cnt].back ()] = scc_cnt + 1;
				if (scc[scc_cnt].back () == u) break;
			}
			++scc_cnt;
		}
	};
	dfs1 (dfs1, 1);
	vector <int> ans (n + 1);
	for (int i = 1; i <= n; ++i) if (dfn[i]) ans[i] = 1;
	for (int i = 0, u; i < scc_cnt; ++i) {
		if (scc[i].size () == 1) {
			u = scc[i][0];
			if (ans[u] && edge[{u, u}]) ans[u] = -1;
		}
		else {
			for (auto &v : scc[i]) {
				if (ans[v]) ans[v] = -1;
			}
		}
	}
	vector <int> vis (n + 1);
	auto dfs2 = [&] (auto && me, int u, int st) -> void {
		vis[u] = true;
		st |= ok[u];
		if (st == 1 && ans[u] == 1) ans[u] = 2;
		for (auto &v : adj[u]) {
			if (vis[v]) continue;
			me (me, v, st);
		}
	};
	dfs2 (dfs2, 1, 0);
	vis.clear (), vis.resize (n + 1);
	queue <int> q;
	for (int i = 1; i <= n; ++i) {
		if (ans[i] == -1) {
			q.push (i);
			vis[i] = true;
		}
	}
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		for (auto &v : adj[u]) {
			if (vis[v]) continue;
			vis[v] = true;
			ans[v] = -1;
			q.push (v);
		}
	}
	for (int i = 1; i <= n; ++i) 
	cout << ans[i] << " \n"[i == n];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}