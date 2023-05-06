#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 1e5 + 5;
const int M = 20;

int n, m, root, tot;
int son[N], dep[N], siz[N];
int dfn[N], rev[N], top[N];
int fa[N][M];
vector <int> adj[N];

int node[N << 2];

void init () {}

void modify (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) {node[rt] = 1; return;}
	int mid = l + r >> 1;
	if (ql <= mid) modify (rt << 1, l, mid, ql, qr);
	if (qr > mid) modify (rt << 1 | 1, mid + 1, r, ql, qr);
}

bool query (int rt, int l, int r, int ql, int qr) {
	if (node[rt]) return 1;
	else if (l == r) return 0;
	int mid = l + r >> 1;
	if (ql <= mid && query (rt << 1, l, mid, ql, qr)) return 1;
	else if (qr > mid && query (rt << 1 | 1, mid + 1, r, ql, qr)) return 1;
	else return 0;
}

void dfs1 (int f, int u, int d) {
	fa[u][0] = f, siz[u] = 1, dep[u] = d;
	for (int i = 1; i < M; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
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
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1, f; i <= n; ++i) {
		cin >> f;
		if (f > 0) adj[f].emplace_back (i);
		else root = i;
	}
	dfs1 (0, root, 1), dfs2 (0, root, root);
	modify (1, 1, n, dfn[root], dfn[root]);
	for (int i = 1, x, ans = 0, mx = 1; i <= m; ++i) {
		cin >> x;
		mx = max (mx, dep[x]);
		if (!query (1, 1, n, dfn[x], dfn[x])) {
			int y = x;
			for (int i = M - 1; i >= 0; --i) {
				if (!fa[y][i]) continue;
				else if (!query (1, 1, n, dfn[fa[y][i]], dfn[fa[y][i]])) y = fa[y][i];
			}
			y = fa[y][0];
			ans += 2 * (dep[x] - dep[y]);
			while (top[x]) modify (1, 1, n, dfn[top[x]], dfn[x]), x = fa[top[x]][0];
		}
		cout << ans - mx + 1 << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}