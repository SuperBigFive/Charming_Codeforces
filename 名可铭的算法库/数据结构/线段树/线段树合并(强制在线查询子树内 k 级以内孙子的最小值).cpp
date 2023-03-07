#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;

int n, m, r, tot;
int root[maxn], val[maxn], fa[maxn], dep[maxn];
int mn[maxn * 40], ls[maxn * 40], rs[maxn * 40];
vector <int> adj[maxn];

void init () {}

void get_query (int &x, int &k, int last) {
	x = ((x + last) % n) + 1;
	k = (k + last) % n;
}

void PushUp (int cnt) {
	if (!mn[ls[cnt]] || !mn[rs[cnt]]) mn[cnt] = max (mn[ls[cnt]], mn[rs[cnt]]);
	else mn[cnt] = min (mn[ls[cnt]], mn[rs[cnt]]);
}

void Update (int &now, int l, int r, int pos, int v) {
	if (!now) now = ++tot;
	if (l == r) {
		mn[now] = v;
		return;
	}
	int mid = l + r >> 1;
	if (pos <= mid) Update (ls[now], l, mid, pos, v);
	else Update (rs[now], mid + 1, r, pos, v);
	PushUp (now);
}

void Merge (int &now, int x, int y, int l, int r) {
	if (!x || !y) {
		now = x + y;
		return;
	}
	now = ++tot;
	if (l == r) {
		if (!mn[x] || !mn[y]) mn[now] = max (mn[x], mn[y]);
		else mn[now] = min (mn[x], mn[y]);
		return;
	}
	int mid = l + r >> 1;
	Merge (ls[now], ls[x], ls[y], l, mid);
	Merge (rs[now], rs[x], rs[y], mid + 1, r);
	PushUp (now);
	return;
}

void dfs1 (int f, int u, int d) {
	fa[u] = f, dep[u] = d;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs1 (u, it, d + 1);
	}
}

void dfs2 (int f, int u) {
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs2 (u, it);
		Merge (root[u], root[u], root[it], 1, maxn);
	}
}

int Query (int cnt, int l, int r, int ql, int qr) {
	int res = INT_MAX;
	if (l >= ql && r <= qr) return mn[cnt] ? mn[cnt] : INT_MAX;
	int mid = l + r >> 1;
	if (ql <= mid) res = min (res, Query (ls[cnt], l, mid, ql, qr));
	if (qr > mid) res = min (res, Query (rs[cnt], mid + 1, r, ql, qr));
	return res;
}

void charming () {
	cin >> n >> r;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, r, 1);
	for (int i = 1; i <= n; ++i) root[i] = ++tot;
	for (int i = 1; i <= n; ++i) {
		Update (root[i], 1, maxn, dep[i], val[i]);
	}
	cin >> m;
	dfs2 (0, r);
	for (int i = 1, p, q, res = 0; i <= m; ++i) {
		cin >> p >> q;
		get_query (p, q, res);
		res = Query (root[p], 1, maxn, dep[p], dep[p] + q);
		cout << res << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}