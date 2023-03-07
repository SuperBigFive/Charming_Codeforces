#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define pii pair <int, int> 
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 4e5 + 5;

int n, m, tot, ans, blo;
int c[maxn], tmp_c[maxn];
int dfn_in[maxn], dfn_out[maxn], rk[maxn], dep[maxn];
int cnt[maxn], res[maxn];
int fa[maxn], st[maxn];
vi adj[maxn];
struct query {
	int l, r;
	int tot, lca;
	bool operator < (const query &a) {
		if (l / blo != a.l / blo) return l / blo < a.l / blo;
		return r < a.r;
	}
}q[maxn];
int h_son[maxn], siz[maxn];
int top[maxn];
bool ok[maxn];

void init () {
	
}

void dfs1 (int f, int u, int d) {
	fa[u] = f;
	dep[u] = d;
	siz[u] = 1;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs1 (u, it, d + 1);
		siz[u] += siz[it];
		if (siz[h_son[u]] < siz[it]) {
			h_son[u] = it;
		}
	}
}

void dfs2 (int f, int u, int t) {
	top[u] = t;
	dfn_in[u] = ++tot;
	rk[tot] = u;
	if (h_son[u]) dfs2 (u, h_son[u], t);
	for (auto it : adj[u]) {
		if (it == f || it == h_son[u]) continue;
		dfs2 (u, it, it);
	}
	dfn_out[u] = ++tot;
	rk[tot] = u;
}

int lca (int a, int b) {
	while (top[a] != top[b]) {
		dep[top[a]] > dep[top[b]] ? a = fa[top[a]] : b = fa[top[b]];
	}
	return dep[a] > dep[b] ? b : a;
}

void upd (int p) {
	++cnt[c[rk[p]]];
	if (cnt[c[rk[p]]] == 1) ++ans;
}

void del (int p) {
	--cnt[c[rk[p]]];
	if (!cnt[c[rk[p]]]) --ans;
}

void move (int x) {
	st[rk[x]] ? del (x) : upd (x);
	st[rk[x]] ^= 1;
}

void charming () {
	cin >> n >> m;
	blo = sqrt (n);
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		tmp_c[i] = c[i];
	}
	sort (tmp_c + 1, tmp_c + 1 + n);
	for (rg i = 1; i <= n; ++i) {
		c[i] = lower_bound (tmp_c + 1, tmp_c + 1 + n, c[i]) - tmp_c;
	}
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[u].pb (v);
		adj[v].pb (u);
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
	for (int i = 1; i <= m; ++i) {
		cout << res[i] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}