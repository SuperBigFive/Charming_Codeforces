#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define eb emplace_back 
using namespace std;
const int maxn = 1e6 + 5;

int n, m;
int val[maxn], diff[maxn];
int son[maxn], fa[maxn];
int siz[maxn], dep[maxn], top[maxn];
vi adj[maxn];

void init () {
	
}

void dfs1 (int f, int u, int d) {
	siz[u] = 1, fa[u] = f, dep[u] = d;
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

int dfs3 (int f, int u) {
	int sum = 0;
	for (auto it : adj[u]) {
		if (it == f) continue;
		sum += dfs3 (u, it);
	}
	val[u] += sum + diff[u];
	return sum + diff[u];
}

int lca (int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] > dep[top[y]]) x = fa[top[x]];
		else y = fa[top[y]];
	}
	if (dep[x] < dep[y]) return x;
	return y;
}

void add (int x, int y) {
	int LCA = lca (x, y);
	++diff[x], ++diff[y];
	--diff[LCA], --diff[fa[LCA]];
}

void charming () {
	cin >> n >> m;
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, 1, 1);
	dfs2 (0, 1, 1);
	int x, y;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		add (x, y);
	}
	dfs3 (0, 1);
	int res = -1;
	for (int i = 1; i <= n; ++i) {
		res = max (res, val[i]);
	}
	cout << res << endl;
}

signed main () {
	//freopen ("input.in", "r", stdin);
	//freopen ("output.out", "w", stdout);
	charming ();
	return 0;
}