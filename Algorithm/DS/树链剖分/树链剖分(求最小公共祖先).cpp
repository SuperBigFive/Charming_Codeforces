#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

int n, m, root, tot;
int fa[maxn], h_son[maxn], siz[maxn], dep[maxn];
int top[maxn], bottom[maxn], dfn[maxn], rk[maxn];
vi adj[maxn];

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

int dfs2 (int f, int u, int t) {
	top[u] = t;
	dfn[u] = ++tot;
	bottom[u] = tot;
	rk[tot] = u;
	if (h_son[u]) dfs2 (u, h_son[u], t);
	for (auto it : adj[u]) {
		if (it == f || it == h_son[u]) continue;
		bottom[u] = max (bottom[u], dfs2 (u, it, it));
	}
	return bottom[u];
}

int lca (int a, int b) {
	while (top[a] != top[b]) {
		dep[top[a]] > dep[top[b]] ? a = fa[top[a]] : b = fa[top[b]];
	}
	return dep[a] > dep[b] ? b : a;
}

void charming () {
	cin >> n >> m >> root;
	int u, v;
	for (int i = 1 ; i < n; ++i) {
		cin >> u >> v;
		adj[u].pb (v);
		adj[v].pb (u);
	}
	dfs1 (0, root, 1);
	dfs2 (0, root, root);
	int x, y;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;
		cout << lca (x, y) << endl;
	}
}

signed main () {
	charming ();
	return 0;
}