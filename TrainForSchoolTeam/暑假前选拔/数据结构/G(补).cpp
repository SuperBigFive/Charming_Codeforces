#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int n, tot;
int dep[N], root[N], ans[N];
int ls[N * 50], rs[N * 50], mx[N * 50], cnt[N * 50];
vector <int> adj[N];

void init () {}

void dfs1 (int f, int u, int d) {
	dep[u] = d;
	for (auto &v : adj[u]) {
		if (v == f) continue;
		dfs1 (u, v, d + 1);
	}
}

void modify (int &rt, int l, int r, int p) {
	if (!rt) rt = ++tot;
	mx[rt] = p, cnt[rt] = 1;
	if (l == r) return;
	int mid = l + r >> 1;
	if (p <= mid) modify (ls[rt], l, mid, p);
	else modify (rs[rt], mid + 1, r, p);
}

void update (int rt) {
	if (cnt[ls[rt]] >= cnt[rs[rt]]) {
		mx[rt] = mx[ls[rt]];
		cnt[rt] = cnt[ls[rt]];
	}
	else {
		mx[rt] = mx[rs[rt]];
		cnt[rt] = cnt[rs[rt]];
	}
}

void merge (int &nrt, int rtu, int rtv, int l, int r) {
	if (!rtu || !rtv) {nrt = rtu + rtv; return;}
	nrt = ++tot;
	if (l == r) {
		mx[nrt] = l;
		cnt[nrt] = cnt[rtu] + cnt[rtv];
		return;
	}
	int mid = l + r >> 1;
	merge (ls[nrt], ls[rtu], ls[rtv], l, mid);
	merge (rs[nrt], rs[rtu], rs[rtv], mid + 1, r);
	update (nrt);
}

void dfs2 (int f, int u) {
	for (auto &v : adj[u]) {
		if (v == f) continue;
		dfs2 (u, v);
		merge (root[u], root[u], root[v], 1, n);
	}
	ans[u] = mx[root[u]] - dep[u];
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, 1, 1);
	for (int i = 1; i <= n; ++i)
	modify (root[i], 1, n, dep[i]);
	dfs2 (0, 1);
	for (int i = 1; i <= n; ++i) cout << ans[i] << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}