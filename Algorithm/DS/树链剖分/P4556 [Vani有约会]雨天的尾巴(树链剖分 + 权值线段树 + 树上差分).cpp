#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m, tot;
int fa[maxn], siz[maxn], dep[maxn], son[maxn];
int top[maxn], dfn[maxn], rk[maxn], bottom[maxn];
int tl[maxn], tr[maxn], num[maxn], mx[maxn], ans[maxn];
vector <pair <int, int> > give[maxn];
vector <int> adj[maxn];

void init () {
	tot = 0;
	for (int i = 0; i < maxn; ++i)
	adj[i].clear (), give[i].clear ();
}

void dfs1 (int f, int u, int d) {
	fa[u] = f, siz[u] = 1, dep[u] = d;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs1 (u, it, d + 1);
		if (siz[it] > siz[son[u]]) son[u] = it;
	}
}

int dfs2 (int f, int u, int tp) {
	dfn[u] = ++tot, rk[tot] = u, top[u] = tp;
	bottom[u] = tot;
	if (son[u]) bottom[u] = dfs2 (u, son[u], tp);
	for (auto it : adj[u]) {
		if (it == f || it == son[u]) continue;
		bottom[u] = max (dfs2 (u, it, it), bottom[u]);
	}
	return dfn[u];
}

void build (int cnt, int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	build (tl[cnt] = ++tot, l, mid);
	build (tr[cnt] = ++tot, mid + 1, r);
}

void update (int cnt, int l, int r, int pos, int val) {
	if (l == r) {
		num[cnt] += val;
		mx[cnt] = l;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) update (tl[cnt], l, mid, pos, val);
	else update (tr[cnt], mid + 1, r, pos, val);
	if (num[tl[cnt]] >= num[tr[cnt]]) {
		num[cnt] = num[tl[cnt]];
		mx[cnt] = mx[tl[cnt]];
	}
	else {
		num[cnt] = num[tr[cnt]];
		mx[cnt] = mx[tr[cnt]];
	}
}

void update1 (int x, int y, int z) {
	while (top[x] != top[y]) {
		if (dep[top[x]] > dep[top[y]]) {
			give[dfn[top[x]]].emplace_back (make_pair (z, 1));
			give[dfn[x] + 1].emplace_back (make_pair (z, -1));
			x = fa[top[x]];
		}
		else {
			give[dfn[top[y]]].emplace_back (make_pair (z, 1));
			give[dfn[y] + 1].emplace_back (make_pair (z, -1));
			y = fa[top[y]];
		}
	}
	if (dep[x] > dep[y]) swap(x, y);
	give[dfn[x]].emplace_back (make_pair (z, 1));
	give[dfn[y] + 1].emplace_back (make_pair (z, -1));
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, 1, 1);
	dfs2 (0, 1, 1);
	tot = 1;
	build (1, 1, 100000);
	for (int i = 1, x, y, z; i <= m; ++i) {
		cin >> x >> y >> z;
		update1 (x, y, z);
	}
	for (int i = 1, p, v; i <= n; ++i) {
		for (auto it : give[i]) {
			p = it.first, v = it.second;
			update (1, 1, 100000, p, v);
		}
		ans[rk[i]] = mx[1];
	}
	for (int i = 1; i <= n; ++i)
	cout << ans[i] << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}