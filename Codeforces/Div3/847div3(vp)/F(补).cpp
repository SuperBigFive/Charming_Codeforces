#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, rt, tot1, tot2;
int fa[N], son[N], dep[N], siz[N];
int dfn[N], rev[N], top[N];
int node[N << 2], lazy[N << 2];
int ls[N << 2], rs[N << 2];
vector <int> adj[N];

void init () {
	for (int i = 1; i <= n; ++i)
	fa[i] = son[i] = dep[i] = siz[i] = 
	dfn[i] = rev[i] = top[i] = 0, adj[i].clear ();
	for (int i = 0; i <= tot2; ++i)
	node[i] = lazy[i] = ls[i] = rs[i] = 0;
	tot1 = 0, tot2 = 1;
}

void dfs1 (int f, int u, int d) {
	fa[u] = f, siz[u] = 1, dep[u] = d;
	for (auto &v : adj[u]) if (v != f) {
		dfs1 (u, v, d + 1);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2 (int f, int u, int tp) {
	dfn[u] = ++tot1, rev[tot1] = u, top[u] = tp;
	if (son[u]) dfs2 (u, son[u], tp);
	for (auto &v : adj[u]) if (v != f && v != son[u]) {
		dfs2 (u, v, v);
	}
}

void build (int cnt, int l, int r) {
	node[cnt] = INT_MAX;
	if (l == r) return;
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot2, l, mid);
	build (rs[cnt] = ++tot2, mid + 1, r);
}

void pushdown (int cnt) {
	if (!lazy[cnt]) return;
	node[ls[cnt]] = min (node[ls[cnt]], lazy[cnt]);
	node[rs[cnt]] = min (node[rs[cnt]], lazy[cnt]);
	if (!lazy[ls[cnt]]) lazy[ls[cnt]] = lazy[cnt];
	else lazy[ls[cnt]] = min (lazy[ls[cnt]], lazy[cnt]);
	if (!lazy[rs[cnt]]) lazy[rs[cnt]] = lazy[cnt];
	else lazy[rs[cnt]] = min (lazy[rs[cnt]], lazy[cnt]);
	lazy[cnt] = 0;
}

void modify (int cnt, int l, int r, int ql, int qr, int k) {
	node[cnt] = min (node[cnt], k);
	if (l >= ql && r <= qr) {
		if (!lazy[cnt]) lazy[cnt] = k;
		else lazy[cnt] = min (lazy[cnt], k);
		return;
	}
	pushdown (cnt);
	int mid = l + r >> 1;
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, k);
}

int query (int cnt, int l, int r, int p) {
	if (l == r) return node[cnt];
	pushdown (cnt);
	int mid = l + r >> 1;
	if (p <= mid) return query (ls[cnt], l, mid, p);
	return query (rs[cnt], mid + 1, r, p);
}

void charming () {
	init ();
	cin >> n >> rt;	
	vector <int> c (n - 1), mx (n - 1);
	for (auto &it : c) cin >> it;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, rt, 1), dfs2 (0, rt, rt), build (1, 1, n);
	mx[0] = 1;
	while (mx[0] < n) mx[0] <<= 1;
	mx[0] <<= 1;
	for (int i = 1, j, pow2 = mx[0], cnt = 1; i < n - 1; i = j) {
		pow2 >>= 1, cnt <<= 1;
		for (j = i; j < min (n - 1, i + cnt); ++j) {
			mx[j] = pow2;
		}
	}
	modify (1, 1, n, dfn[rt], dfn[rt], dep[rt]);
	for (int i = 0, res = INT_MAX; i < n - 1; ++i) {
		int cnt = 0, cur = c[i];
		while (cnt < mx[i] && cur) {
			res = min (res, cnt + query (1, 1, n, dfn[cur]) - dep[cur]);
			cur = fa[cur];
			++cnt;
		}
		cur = c[i];
		do {
			modify (1, 1, n, dfn[top[cur]], dfn[cur], dep[c[i]]);
			cur = fa[top[cur]];
		} while (cur);
		cout << res << " \n"[i == n - 2];
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}