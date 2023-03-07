#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e5 + 5;

int n, q, tot;
int son[maxn], fa[maxn];
int siz[maxn], dep[maxn], top[maxn];
int root[maxn], mx[maxn << 6], num[maxn << 6];
int ls[maxn << 6], rs[maxn << 6], ans[maxn];
vector <int> adj[maxn];

void init () {}

void dfs1 (int f, int u, int d) {
	siz[u] = 1, fa[u] = f, dep[u] = d;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs1 (u, it, d + 1);
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
		dep[top[x]] > dep[top[y]] ? x = fa[top[x]] : y = fa[top[y]];
	}
	return dep[x] < dep[y] ? x : y;
}

void PushUp (int cnt) {
	if (num[ls[cnt]] >= num[rs[cnt]]) {
		mx[cnt] = mx[ls[cnt]];
		num[cnt] = num[ls[cnt]];
	}
	else {
		mx[cnt] = mx[rs[cnt]];
		num[cnt] = num[rs[cnt]];
	}
}

void Update (int &now, int l, int r, int pos, int val) {
	if (!now) now = ++tot;
	if (l == r) {
		num[now] += val;
		mx[now] = l;
		return;
	}
	int mid = l + r >> 1;
	if (pos <= mid) Update (ls[now], l, mid, pos, val);
	else Update (rs[now], mid + 1, r, pos, val);
	PushUp (now);
}


int Merge (int x, int y, int l, int r) {
	if (!x) return y;
	if (!y) return x;
	if (l == r) {
		num[x] += num[y];
		mx[x] = l;
		return x;
	}
	int mid = l + r >> 1;
	ls[x] = Merge (ls[x], ls[y], l, mid);
	rs[x] = Merge (rs[x], rs[y], mid + 1, r);
	PushUp (x);
	return x;
}

void dfs3 (int f, int u) {
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs3 (u, it);
		Merge (root[u], root[it], 1, maxn);
	}
	if (num[root[u]]) ans[u] = mx[root[u]];
}

void charming () {
	cin >> n >> q;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, 1, 1);
	dfs2 (0, 1, 1);
	for (int i = 1; i <= n; ++i) {
		root[i] = ++tot;
	}
	int x, y, z, LCA;
	for (int i = 1; i <= q; ++i) {
		cin >> x >> y >> z;
		LCA = lca (x, y);
		Update (root[x], 1, maxn, z, 1);
		Update (root[y], 1, maxn, z, 1);
		Update (root[LCA], 1, maxn, z, -1);
		Update (root[fa[LCA]], 1, maxn, z, -1);
	}
	dfs3 (0, 1);
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}