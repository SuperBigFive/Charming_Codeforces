#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

int n, m, tot;
int fa[maxn], son[maxn], siz[maxn], dep[maxn];
int top[maxn], w[maxn], root[maxn], ans[maxn];
int node[maxn * 60], ls[maxn * 60], rs[maxn * 60];
vector <int> adj[maxn];

void init () {}

void dfs1 (int f, int u, int d) {
	fa[u] = f, siz[u] = 1, dep[u] = d;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs1 (u, it, d + 1);
		siz[u] += siz[it];
		if (siz[it] > siz[son[u]]) son[u] = it;
	}
}

void dfs2 (int f, int u, int tp) {
	top[u] = tp;
	if (son[u]) dfs2 (u, son[u], tp);
	for (auto it : adj[u]) {
		if (it == f || it == son[u]) continue;
		dfs2 (u, it, it);
	}
}

int lca (int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap (x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

void modify (int &cnt, int l, int r, int d, int k) {
	if (!cnt) cnt = ++tot;
	if (l == r) {
		node[cnt] += k;
		return;
	}
	int mid = l + r >> 1;
	if (d <= mid) modify (ls[cnt], l, mid, d, k);
	else modify (rs[cnt], mid + 1, r, d, k);
}

int merge (int x, int y, int l, int r) {
	if (!x || !y) return x + y;
	int now = ++tot;
	if (l == r) {
		node[now] = node[x] + node[y];
		return now;
	}
	int mid = l + r >> 1;
	ls[now] = merge (ls[x], ls[y], l, mid);
	rs[now] = merge (rs[x], rs[y], mid + 1, r);
	return now;
}

int query (int cnt, int l, int r, int pos) {
	if (l == r) return node[cnt];
	int mid = l + r >> 1;
	if (pos <= mid) return query (ls[cnt], l, mid, pos);
	return query (rs[cnt], mid + 1, r, pos);
}

void dfs (int f, int u) {
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs (u, it);
		root[u] = merge (root[u], root[it], 1, n << 1);
	}
	if (w[u] && n + dep[u] + w[u] <= n << 1)
	ans[u] += query (root[u], 1, n << 1, n + dep[u] + w[u]);
	ans[u] += query (root[u], 1, n << 1, n + dep[u] - w[u]);
}

void charming () {
	cin >> n >> m;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, 1, 1), dfs2 (0, 1, 1);
	for (int i = 1; i <= n; ++i) cin >> w[i];
	for (int i = 1, u, v, LCA; i <= m; ++i) {
		cin >> u >> v;
		LCA = lca (u, v);
		modify (root[u], 1, n << 1, n + dep[u], 1);
		modify (root[LCA], 1, n << 1, n + dep[u], -1);
		modify (root[v], 1, n << 1, n + dep[LCA] * 2 - dep[u], 1);
		modify (root[fa[LCA]], 1, n << 1, n + dep[LCA] * 2 - dep[u], -1);
	}
	dfs (0, 1);
	for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

signed main () {
	charming ();
	return 0;
}