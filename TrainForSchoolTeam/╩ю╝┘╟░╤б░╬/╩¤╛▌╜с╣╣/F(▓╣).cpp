#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e6 + 5;

int n, q, tot;
int fa[N], siz[N], son[N], dep[N];
int dfn[N], rev[N], bot[N], top[N];
int node[N << 2], root[N], a[N];
int ch[N << 2][2];
vector <int> adj[N];

void init () {}

void dfs1 (int f, int u, int d) {
	fa[u] = f, siz[u] = 1, dep[u] = d;
	for (auto &v : adj[u]) {
		if (v == f) continue;
		dfs1 (u, v, d + 1);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2 (int f, int u, int t) {
	dfn[u] = ++tot, rev[tot] = u, top[u] = t;
	if (son[u]) dfs2 (u, son[u], t);
	for (auto &v : adj[u]) {
		if (v == f || v == son[u]) continue;
		dfs2 (u, v, v);
	}
	bot[u] = tot;
}

void insert (int &nrt, int pre, int val) {
	nrt = ++tot;
	int cur = nrt;
	for (int i = 31, chk; i >= 0; --i) {
		chk = (val >> i) & 1;
		ch[cur][chk ^ 1] = ch[pre][chk ^ 1];
		cur = ch[cur][chk] = ++tot;
		pre = ch[pre][chk];
		node[cur] = node[pre] + 1;
	}
}

int Xor_mx (int rt_l, int rt_r, int x) {
	int res = 0;
	for (int i = 31, chk = 0; i >= 0; --i) {
		chk = (((x >> i) & 1) ^ 1);
		if (node[ch[rt_r][chk]] - node[ch[rt_l][chk]] > 0) {
			res += (1 << i);
			rt_r = ch[rt_r][chk];
			rt_l = ch[rt_l][chk];
		} else {
			rt_r = ch[rt_r][chk ^ 1];
			rt_l = ch[rt_l][chk ^ 1];
		}
	}
	return res;
}

int query_tree (int u, int x) {
	return Xor_mx (root[dfn[u] - 1], root[bot[u]], x);
}

int query_path (int u, int v, int x) {
	int res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap (u, v);
		res = max (res, Xor_mx (root[dfn[top[u]] - 1], root[dfn[u]], x));
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap (u, v);
	return max (res, Xor_mx (root[dfn[u] - 1], root[dfn[v]], x));
}

void charming () {
	init ();
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, 1, 1), dfs2 (0, 1, 1);
	tot = 0;
	for (int i = 1; i <= n; ++i) 
	insert (root[i], root[i - 1], a[rev[i]]);
	for (int i = 1, opt, x, y, z; i <= q; ++i) {
		cin >> opt;
		if (opt == 1) {
			cin >> x >> z;
			cout << query_tree (x, z) << endl;
		}
		else {
			cin >> x >> y >> z;
			cout << query_path (x, y, z) << endl;
		}
	}
}
 
signed main () {
	charming ();
	return 0;
}