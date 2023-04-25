#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 4e5 + 5;
const int blo = 500;

struct query {
	int l, r;
	int tot, lca;
	bool operator < (const query &a) {
		if (l / blo != a.l / blo) return l / blo < a.l / blo;
		return r < a.r;
	}
}q[N];

int n, m, tot, ans;
int c[N], tmp_c[N], son[N], siz[N], dep[N];
int dfn_in[N], dfn_out[N], rev[N], top[N];
int cnt[N], res[N];
int fa[N], st[N];
vector <int> adj[N];

void init () {}

void dfs1 (int f, int u, int d) {
	fa[u] = f, siz[u] = 1, dep[u] = d;
	for (auto v : adj[u]) {
		if (v == f) continue;
		dfs1 (u, v, d + 1);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2 (int f, int u, int t) {
	dfn_in[u] = ++tot, rev[tot] = u, top[u] = t;
	if (son[u]) dfs2 (u, son[u], t);
	for (auto v : adj[u]) {
		if (v == f || v == son[u]) continue;
		dfs2 (u, v, v);
	}
	dfn_out[u] = ++tot, rev[tot] = u;
}

int lca (int a, int b) {
	while (top[a] != top[b]) {
		dep[top[a]] > dep[top[b]] ? a = fa[top[a]] : b = fa[top[b]];
	}
	return dep[a] > dep[b] ? b : a;
}

void upd (int p) {
	++cnt[c[rev[p]]];
	if (cnt[c[rev[p]]] == 1) ++ans;
}

void del (int p) {
	--cnt[c[rev[p]]];
	if (!cnt[c[rev[p]]]) --ans;
}

void move (int x) {
	st[rev[x]] ? del (x) : upd (x);
	st[rev[x]] ^= 1;
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		tmp_c[i] = c[i];
	}
	sort (tmp_c + 1, tmp_c + 1 + n);
	for (int i = 1; i <= n; ++i) {
		c[i] = lower_bound (tmp_c + 1, tmp_c + 1 + n, c[i]) - tmp_c;
	}
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, 1, 1);
	dfs2 (0, 1, 1);
	int l, r;
	for (int i = 1; i <= m; ++i) {
		cin >> q[i].l >> q[i].r;
		q[i].tot = i;
		u = q[i].l, v = q[i].r;
		if (dfn_in[u] > dfn_in[v]) swap (u, v);
		int Lca = lca (u, v);
		if (Lca != u) {
			q[i].l = dfn_out[u];
			q[i].lca = Lca;
		}
		else {
			q[i].l = dfn_in[u];
			q[i].lca = 0;
		}
		q[i].r = dfn_in[v];
	}
	sort (q + 1, q + 1 + m);
	int pl = 1, pr = 0, ql, qr;
	ans = 0;
	for (int i = 1; i <= m; ++i) {
		ql = q[i].l, qr = q[i].r;
		while (pl < ql) move (pl++);
		while (pl > ql) move (--pl); 
		while (pr < qr) move (++pr);
		while (pr > qr) move (pr--);   	  
		if (q[i].lca) move (dfn_in[q[i].lca]);
		res[q[i].tot] = ans; 
		if (q[i].lca) move (dfn_in[q[i].lca]);
	}
	for (int i = 1; i <= m; ++i)
	cout << res[i] << endl;
}

signed main () {
	charming ();
	return 0;
}