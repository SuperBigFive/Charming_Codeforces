#include <bits/stdc++.h>
#define ll long long
#define int ll
#define nls node[cnt].ls
#define nrs node[cnt].rs
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 2019;

struct Node {
	int sum1, sum2;
	int siz1, siz2;
	int ls, rs;
	int lazy;
}node[maxn << 2];
int n, m, tot;
int fa[maxn], son[maxn], siz[maxn], dep[maxn];
int dfn[maxn], rk[maxn], top[maxn], bot[maxn];
int val[maxn], sum1[maxn], sum2[maxn];
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
	siz[u] = siz[u] % mod;
	sum1[u] = val[u] * siz[u] % mod;
	sum2[u] = (val[u] * siz[u]) % mod * siz[u] % mod;
}

void dfs2 (int f, int u, int tp) {
	dfn[u] = ++tot, rk[tot] = u, top[u] = tp;
	if (son[u]) dfs2 (u, son[u], tp);
	for (auto it : adj[u]) {
		if (it == f || it == son[u]) continue;
		dfs2 (u, it, it);
	}
	bot[u] = tot;
}

void update (int cnt) {
	node[cnt].sum1 = (node[nls].sum1 + node[nrs].sum1) % mod;
	node[cnt].sum2 = (node[nls].sum2 + node[nrs].sum2) % mod;
	node[cnt].siz1 = (node[nls].siz1 + node[nrs].siz1) % mod;
	node[cnt].siz2 = (node[nls].siz2 + node[nrs].siz2) % mod;
}

void build (int cnt, int l, int r) {
	if (l == r) {
		node[cnt].sum1 = sum1[rk[l]] % mod;
		node[cnt].sum2 = sum2[rk[l]] % mod;
		node[cnt].siz1 = siz[rk[l]] % mod;
		node[cnt].siz2 = siz[rk[l]] * siz[rk[l]] % mod;
		node[cnt].lazy = 0;
		return;
	}
	int mid = l + r >> 1;
	build (nls = ++tot, l, mid);
	build (nrs = ++tot, mid + 1, r);
	update (cnt);
}

void pushdown (int cnt) {
	node[nls].sum1 = (node[nls].sum1 + node[cnt].lazy * node[nls].siz1) % mod;
	node[nrs].sum1 = (node[nrs].sum1 + node[cnt].lazy * node[nrs].siz1) % mod;
	
	node[nls].sum2 = (node[nls].sum2 + node[cnt].lazy * node[nls].siz2) % mod;
	node[nrs].sum2 = (node[nrs].sum2 + node[cnt].lazy * node[nrs].siz2) % mod;
	
	node[nls].lazy = (node[nls].lazy + node[cnt].lazy) % mod;
	node[nrs].lazy = (node[nrs].lazy + node[cnt].lazy) % mod;
	
	node[cnt].lazy = 0;
}

void modify (int cnt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		node[cnt].sum1 = (node[cnt].sum1 + node[cnt].siz1 * k) % mod;
		node[cnt].sum2 = (node[cnt].sum2 + node[cnt].siz2 * k) % mod;
		node[cnt].lazy = (node[cnt].lazy + k) % mod;
		return;
	}
	int mid = l + r >> 1;
	pushdown (cnt);
	if (ql <= mid) modify (nls, l, mid, ql, qr, k);
	if (qr > mid) modify (nrs, mid + 1, r, ql, qr, k);
	node[cnt].sum1 = (node[nls].sum1 + node[nrs].sum1) % mod;
	node[cnt].sum2 = (node[nls].sum2 + node[nrs].sum2) % mod;
}

void add_path (int u, int v, int w) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap (u, v);
		modify (0, 1, n, dfn[top[u]], dfn[u], w);
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap (u, v);
	if (u == v) return;
	modify (0, 1, n, dfn[u] + 1, dfn[v], w);
}

int query (int cnt, int l, int r, int ql, int qr, int x) {
	if (l >= ql && r <= qr) return (node[cnt].sum1 * x - node[cnt].sum2) % mod;
	int mid = l + r >> 1, res = 0;
	pushdown (cnt);
	if (ql <= mid) res += query (nls, l, mid, ql, qr, x);
	if (qr > mid) res += query (nrs, mid + 1, r, ql, qr, x);
	return ((res % mod) + mod) % mod;
}

void charming () {
	cin >> n >> m;
	for (int i = 2, q, c; i <= n; ++i) {
		cin >> q >> c;
		adj[q].emplace_back (i);
		val[i] = c;
	}
	dfs1 (0, 1, 1), dfs2 (0, 1, 1);
	tot = 0, build (0, 1, n);
	char opt[5];
	int u, v, w, p;
	for (int i = 1; i <= m; ++i) {
		cin >> opt + 1;
		if (opt[1] == 'I') {
			cin >> u >> v >> w;
			add_path (u, v, w % mod);
		}
		else {
			cin >> p;
			if (dfn[p] == bot[p]) cout << 0 << endl;
			else cout << query (0, 1, n, dfn[p] + 1, bot[p], siz[p]) << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}