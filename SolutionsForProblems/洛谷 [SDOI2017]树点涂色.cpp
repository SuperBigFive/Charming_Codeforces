#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e5 + 5;

int n, m, tot;
int fa1[maxn], fa2[maxn], siz[maxn], son[maxn], dep[maxn];
int top[maxn], dfn[maxn], rk[maxn], bot[maxn];
int mx[maxn << 2], ls[maxn << 2], rs[maxn << 2], lazy[maxn << 2];
int ch[maxn][2];
vector <int> adj[maxn];

void dfs1 (int f, int u, int d) {
	fa1[u] = f, siz[u] = 1, dep[u] = d;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs1 (u, it, d + 1);
		siz[u] += siz[it];
		if (siz[it] > siz[son[u]]) son[u] = it;
	}
}

int dfs2 (int f, int u, int tp) {
	top[u] = tp;
	dfn[u] = ++tot, rk[tot] = u, bot[u] = tot;
	if (son[u]) bot[u] = max (bot[u], dfs2 (u, son[u], tp));
	for (auto it : adj[u]) {
		if (it == f || it == son[u]) continue;
		bot[u] = max (bot[u], dfs2 (u, it, it));
	}
	return bot[u];
}

int lca (int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap (x, y);
		x = fa1[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

void update (int cnt) {mx[cnt] = max (mx[ls[cnt]], mx[rs[cnt]]);}

void build (int cnt, int l, int r) {
	if (l == r) {
		mx[cnt] = dep[rk[l]];
		lazy[cnt] = 0;
		return;
	}
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
	update (cnt);
}

void pushdown (int cnt) {
	mx[ls[cnt]] += lazy[cnt];
	mx[rs[cnt]] += lazy[cnt];
	
	lazy[ls[cnt]] += lazy[cnt];
	lazy[rs[cnt]] += lazy[cnt];	
	
	lazy[cnt] = 0;
}

void add (int cnt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		lazy[cnt] += k;
		mx[cnt] += k;
		return;
	}
	pushdown (cnt);
	int mid = l + r >> 1;
	if (ql <= mid) add (ls[cnt], l, mid, ql, qr, k);
	if (qr > mid) add (rs[cnt], mid + 1, r, ql, qr, k);
	update (cnt);
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return mx[cnt];
	pushdown (cnt);
	int mid = l + r >> 1;
	int res = -1;
	if (ql <= mid) res = max (res, query (ls[cnt], l, mid, ql, qr));
	if (qr > mid) res = max (res, query (rs[cnt], mid + 1, r, ql, qr));
	return res;
}

namespace LCT {
	bool Get (int x) {return x == ch[fa2[x]][1];}
	bool isRoot (int x) {return x != ch[fa2[x]][0] && x != ch[fa2[x]][1];}
	
	void Rotate (int x) {
		int y = fa2[x], z = fa2[y], chk = Get (x);
		if (!isRoot (y)) ch[z][Get (y)] = x;
		if (ch[x][chk ^ 1]) fa2[ch[x][chk ^ 1]] = y;
		ch[y][chk] = ch[x][chk ^ 1];
		ch[x][chk ^ 1] = y;
		fa2[y] = x, fa2[x] = z;
	}
	
	void Splay (int x) {
		for (int f = fa2[x]; f = fa2[x], !isRoot (x); Rotate (x)) {
			if (!isRoot (f)) Rotate (Get (f) == Get (x) ? f : x);
		}
	}
	
	int findRoot (int x) {
		while (ch[x][0]) x = ch[x][0];
		return x;
	}
	
	int Access (int x) {
		int last, tmp;
		for (last = 0; x; last = x, x = fa2[x]) {
			Splay (x);
			if (ch[x][1]) {
				tmp = findRoot (ch[x][1]);
				add (0, 1, n, dfn[tmp], bot[tmp], 1);
			}
			if (last) {
				tmp = findRoot (last);
				add (0, 1, n, dfn[tmp], bot[tmp], -1);
			}
			ch[x][1] = last;
		}
		return last;
	}
	
}

void init () {}

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
	tot = 0;
	build (0, 1, n);
	for (int i = 1; i <= n; ++i) fa2[i] = fa1[i];
	int opt, x, y, LCA, val1, val2, val3;
	for (int i = 1; i <= m; ++i) {
		cin >> opt >> x;
		if (opt == 1) LCT :: Access (x);
		else if (opt == 2) {
			cin >> y;
			LCA = lca (x, y);
			val1 = query (0, 1, n, dfn[x], dfn[x]);
			val2 = query (0, 1, n, dfn[y], dfn[y]);
			val3 = query (0, 1, n, dfn[LCA], dfn[LCA]);
			cout << val1 + val2 - (val3 << 1) + 1 << endl;
		}
		else cout << query (0, 1, n, dfn[x], bot[x]) << endl;
	}
}

signed main () {
	charming ();
	return 0;
}