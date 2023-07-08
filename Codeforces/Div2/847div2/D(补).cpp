#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, tot, scc_cnt;

void init () {tot = scc_cnt = 0;}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5), dfn (n + 5), low (n + 5), bel (n + 5), in (n + 5);
	vector <vector <int> > adj (n + 5), nadj (n + 5), revadj (n + 5), scc (1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i + a[i] >= 1 && i + a[i] <= n)
		adj[i].emplace_back (i + a[i]);
	}
	vector <int> stk;
	auto tarjan = [&] (auto && me, int u) -> void {
		dfn[u] = low[u] = ++tot;
		stk.emplace_back (u);
		for (auto &v : adj[u]) {
			if (!dfn[v]) {
				me (me, v);
				low[u] = min (low[u], low[v]);
			}
			else if (!bel[v]) low[u] = min (low[u], dfn[v]);
		}
		if (low[u] >= dfn[u]) {
			++scc_cnt;
			vector <int> nxt_scc;
			do {
				nxt_scc.emplace_back (stk.back ());
				bel[stk.back ()] = scc_cnt;
				stk.pop_back ();
			} while (nxt_scc.back () != u);
			scc.emplace_back (nxt_scc);
		}
	};
	for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan (tarjan, i);
	for (int u = 1; u <= n; ++u) {
		for (auto &v : adj[u]) {
			if (bel[u] == bel[v] || scc[bel[u]].size () > 1
			|| scc[bel[v]].size () > 1) continue;
			nadj[bel[v]].emplace_back (bel[u]);
		}
	}
	vector <int> siz (n + 5);
	auto dfs1 = [&] (auto && me, int u) -> void {
		siz[u] = 1;
		for (auto &v : nadj[u]) {
			me (me, v);
			siz[u] += siz[v];
		}
	};
	int sum = 0;
	for (int i = 1; i <= scc_cnt; ++i) {
		if (scc[i].size () == 1 && !adj[scc[i][0]].size ()) {
			dfs1 (dfs1, i);
			sum += siz[i];
		}
	}
	int res = 0;
	vector <int> vis (n + 5);
	vector <int> pre (n + 5);
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + (siz[i] > 0);
	}
	auto dfs2 = [&] (auto && me, int u) -> void {
		vis[u] = true;
		res += sum - siz[bel[u]] + n + 1;
		for (auto &v : adj[u]) {
			if (vis[v]) continue;
			me (me, v);
		}
	};
	dfs2 (dfs2, 1);
	if (siz[1]) {
		for (int i = 1; i <= n; ++i) 
		if (!vis[i]) res += 2 * n + 1;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}