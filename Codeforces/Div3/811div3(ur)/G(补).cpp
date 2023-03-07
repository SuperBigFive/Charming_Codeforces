#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n, tot;
int a[maxn], b[maxn];
int siz[maxn], fa[maxn][32], h_son[maxn], dep[maxn];
int top[maxn], dfn[maxn], res[maxn];
vi adj[maxn];

void init () {
	for (int i = 1; i <= n; ++i) {
		res[i] = siz[i] = h_son[i] = dep[i] = top[i] = dfn[i] = res[i] = 0;
		adj[i].clear ();
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 32; ++j) fa[i][j] = 0;
	}
}

int dfs1 (int f, int u, int d) {
	siz[u] = 1;
	fa[u][0] = f;
	for (int i = 1; i <= 20; ++i) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	dep[u] = d;
	for (auto it : adj[u]) {
		siz[u] += dfs1 (u, it, d + 1);
		if (siz[it] > siz[h_son[u]]) h_son[u] = it;
	}
	return siz[u];
}

void dfs2 (int f, int u, int tp) {
	top[u] = tp;
	dfn[u] = ++tot;
	if (h_son[u]) dfs2 (u, h_son[u], tp);
	for (auto it : adj[u]) {
		if (it == h_son[u]) continue;
		dfs2 (u, it, it);
	}
}

void dfs3 (int f, int u) {
	a[u] += a[f];
	b[u] += b[f];
	for (auto it : adj[u]) {
		dfs3 (u, it);
	}
}

void get_res (int u) {
	ll tmp_a = a[u], tmp_u = u;
	while (b[top[u]] > tmp_a) {
		u = fa[top[u]][0];
	}
	for (int i = 20; i >= 0; --i) {
		if (fa[u][i] && b[fa[u][i]] > tmp_a) u = fa[u][i];
	}
	if (b[u] > tmp_a) u = fa[u][0];
	res[tmp_u] = dep[u];
}

void charming () {
	init ();
	scanf ("%lld", &n);
	int f;
	for (int i = 2; i <= n; ++i) {
		scanf ("%lld%lld%lld", &f, &a[i], &b[i]);
		adj[f].pb (i);
	}
	dfs1 (0, 1, 0);
	dfs2 (0, 1, 1);
	dfs3 (0, 1);
	for (int i = 2; i <= n; ++i) {
		get_res (i);
	}
	for (int i = 2; i <= n; ++i) {
		printf ("%lld ", res[i]);
	}
	printf ("\n");
}

signed main () {
	scanf ("%d", &t);
	while (t--) charming ();
	return 0;
}