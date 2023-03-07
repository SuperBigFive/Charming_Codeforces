#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e4 + 5;

int t, n, q, tot;
int val[maxn];
int fa[maxn], son[maxn], siz[maxn], dep[maxn];
int dfn[maxn], rk[maxn], top[maxn], bot[maxn];
int ans1[maxn << 2], ans2[maxn << 2], lazy[maxn << 2];
int mn[maxn << 2], mx[maxn << 2];
int ls[maxn << 2], rs[maxn << 2];
vector <int> adj[maxn];

void init () {
	tot = 0;
	for (int i = 1; i <= n; ++i) {
		adj[i].clear ();
		son[i] = 0;
	}
}

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
	dfn[u] = ++tot, rk[tot] = u, top[u] = tp;
	if (son[u]) dfs2 (u, son[u], tp);
	for (auto it : adj[u]) {
		if (it == f || it == son[u]) continue;
		dfs2 (u, it, it);
	}
	bot[u] = tot;
}

void update (int cnt) {
	ans1[cnt] = max ({ans1[ls[cnt]], ans1[rs[cnt]], mx[rs[cnt]] - mn[ls[cnt]], 1ll * 0});
	ans2[cnt] = max ({ans2[ls[cnt]], ans2[rs[cnt]], mx[ls[cnt]] - mn[rs[cnt]], 1ll * 0}); 
	mn[cnt] = min (mn[ls[cnt]], mn[rs[cnt]]);
	mx[cnt] = max (mx[ls[cnt]], mx[rs[cnt]]);
}

void build (int cnt, int l, int r) {
	lazy[cnt] = 0;
	if (l == r) {
		ans1[cnt] = ans2[cnt] = 0;
		mn[cnt] = mx[cnt] = val[rk[l]];
		return;
	}
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
	update (cnt);
}

void pushdown (int cnt) {
	if (!lazy[cnt]) return;
	mx[ls[cnt]] += lazy[cnt];
	mx[rs[cnt]] += lazy[cnt];
	
	mn[ls[cnt]] += lazy[cnt];
	mn[rs[cnt]] += lazy[cnt];
	
	lazy[ls[cnt]] += lazy[cnt];
	lazy[rs[cnt]] += lazy[cnt];
	
	lazy[cnt] = 0;
}

void modify (int cnt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		mx[cnt] += k;
		mn[cnt] += k;
		lazy[cnt] += k;
		return;
	}
	pushdown (cnt);
	int mid = l + r >> 1;
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, k);
	update (cnt);
}

int query (int cnt, int l, int r, int ql, int qr, int &nxt_mn, int &nxt_mx, int st) {
	if (l >= ql && r <= qr) {
		nxt_mn = min (nxt_mn, mn[cnt]);
		nxt_mx = max (nxt_mx, mx[cnt]);
		return st ? ans1[cnt] : ans2[cnt];
	}
	int mid = l + r >> 1;
	pushdown (cnt);
	if (qr <= mid) return query (ls[cnt], l, mid, ql, qr, nxt_mn, nxt_mx, st);
	if (ql > mid) return query (rs[cnt], mid + 1, r, ql, qr, nxt_mn, nxt_mx, st);
	int tmp_mn1 = INT_MAX, tmp_mx1 = 0;
	int res1 = query (ls[cnt], l, mid, ql, qr, tmp_mn1, tmp_mx1, st);
	nxt_mn = min (tmp_mn1, nxt_mn), nxt_mx = max (tmp_mx1, nxt_mx);
	int tmp_mn2 = INT_MAX, tmp_mx2 = 0;
	int res2 = query (rs[cnt], mid + 1, r, ql, qr, tmp_mn2, tmp_mx2, st);
	nxt_mn = min (tmp_mn2, nxt_mn), nxt_mx = max (tmp_mx2, nxt_mx);
	return max ({res1, res2, (st ? tmp_mx2 - tmp_mn1 : tmp_mx1 - tmp_mn2)});
}

void add_path (int u, int v, int k) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap (u, v);
		modify (0, 1, n, dfn[top[u]], dfn[u], k);
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap (u, v);
	modify (0 ,1, n, dfn[u], dfn[v], k);
}

void get_pro (int u, int v) {
	int mnu = INT_MAX, mxu = 0, ansu = 0;
	int mnv = INT_MAX, mxv = 0, ansv = 0;
	int nxt_mn = INT_MAX, nxt_mx = 0;
	while (top[u] != top[v]) {
		nxt_mn = INT_MAX, nxt_mx = 0;
		if (dep[top[u]] > dep[top[v]]) {
			ansu = max ({ansu, query (0, 1, n, dfn[top[u]], dfn[u], nxt_mn, nxt_mx, 0), nxt_mx - mnu});
			mnu = min (mnu, nxt_mn), mxu = max (mxu, nxt_mx);
			u = fa[top[u]];
		}
		else {
			ansv = max ({ansv, query (0, 1, n, dfn[top[v]], dfn[v], nxt_mn, nxt_mx, 1), mxv - nxt_mn});
			mnv = min (mnv, nxt_mn), mxv = max (mxv, nxt_mx);
			v = fa[top[v]];
		}
	}
	nxt_mn = INT_MAX, nxt_mx = 0;
	if (dep[u] < dep[v]) {
		ansu = max ({ansu, query (0, 1, n, dfn[u], dfn[v], nxt_mn, nxt_mx, 1), nxt_mx - mnu});
		mnu = min (mnu, nxt_mn), mxu = max (mxu, nxt_mx);
		cout << max ({ansu, ansv, mxv - mnu}) << endl;
	}
	else {
		ansv = max ({ansv, query (0, 1, n, dfn[v], dfn[u], nxt_mn, nxt_mx, 0), mxv - nxt_mn});
		mnv = min (mnv, nxt_mn), mxv = max (mxv, nxt_mx);
		cout << max ({ansu, ansv, mxv - mnu}) << endl;
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, 1, 1);
	dfs2 (0, 1, 1);
	tot = 0, build (0, 1, n);
	cin >> q;
	for (int i = 1, x, y, v; i <= q; ++i) {
		cin >> x >> y >> v;
		get_pro (x, y);
		add_path (x, y, v);
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}