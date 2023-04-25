#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 5e6 + 5;
const int M = 6;

int n, m;
int a[N], vis[N], phi[N], dep[N];
int node[N], siz[N], ans[N], mx_dep[N];
int fa[N][M];
vector <int> adj[N];

void init () {}

void get_phi () {
	vector <int> prim;
	phi[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) prim.emplace_back (i), phi[i] = i - 1;
		for (int j = 0; j < prim.size () && i * prim[j] < N; ++j) {
			vis[i * prim[j]] = 1;
			if (i % prim[j] == 0) {
				phi[i * prim[j]] = phi[i] * prim[j];
				break;
			}
			else phi[i * prim[j]] = phi[prim[j]] * phi[i]; 
		}
	}
}

void dfs (int f, int u, int d) {
	dep[u] = d;
	fa[u][0] = f;
	for (int i = 1; i < M; ++i) 
	fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto &v : adj[u]) {
		if (v == f) continue;
		dfs (u, v, d + 1);
	}
}

int get_lca (int u, int v) {
	if (dep[u] < dep[v]) swap (u, v);
	for (int i = M - 1; i >= 0; --i) {
		if (dep[fa[u][i]] > dep[v]) u = fa[u][i];
	}
	if (dep[u] != dep[v]) u = fa[u][0];
	if (u == v) return u;
	for (int i = M - 1; i >= 0; --i) {
		if (fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}

void pushup (int rt) {
	int lca = get_lca (node[rt << 1], node[rt << 1 | 1]);
	node[rt] = lca;
	ans[rt] = ans[rt << 1] + ans[rt << 1 | 1] + (dep[node[rt << 1]] - dep[lca]) 
	* siz[rt << 1] + (dep[node[rt << 1 | 1]] - dep[lca]) * siz[rt << 1 | 1];
	mx_dep[rt] = max (mx_dep[rt << 1], mx_dep[rt << 1 | 1]);
}

void build (int rt, int l, int r) {
	siz[rt] = r - l + 1;
	if (l == r) {
		cin >> node[rt];
		a[l] = node[rt];
		mx_dep[rt] = dep[node[rt]];
		ans[rt] = 0;
		return;
	}
	int mid = l + r >> 1;
	build (rt << 1, l, mid);
	build (rt << 1 | 1, mid + 1, r);
	pushup (rt);
}

void modify (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) {
		if (mx_dep[rt] <= 1) return;
		else if (l == r) {
			node[rt] = phi[node[rt]];
			--mx_dep[rt];
			return;			
		}
	}
	int mid = l + r >> 1;
	if (ql <= mid) modify (rt << 1, l, mid, ql, qr);
	if (qr > mid) modify (rt << 1 | 1, mid + 1, r, ql, qr);
	pushup (rt);
}

array <int, 3> query (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return (array <int, 3>) {node[rt], ans[rt], siz[rt]};
	array <int, 3> nans = {-1, -1, -1}, tmp;
	int mid = l + r >> 1;
	if (ql <= mid) nans = query (rt << 1, l, mid, ql, qr);
	if (qr > mid) {
		tmp = query (rt << 1 | 1, mid + 1, r, ql, qr);
		if (nans[0] == -1) nans = tmp;
		else {
			int lca = get_lca (nans[0], tmp[0]);
			nans[1] += tmp[1] + (dep[nans[0]] - dep[lca]) * nans[2]
			+ (dep[tmp[0]] - dep[lca]) * tmp[2];
			nans[2] += tmp[2];
			nans[0] = lca;
		}
	}
	return nans;
}

void charming () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	init ();
	cin >> n >> m;
	for (int i = 2; i < N; ++i)
	adj[phi[i]].emplace_back (i);
	dfs (0, 1, 1);
	build (1, 1, n);
	for (int i = 1, opt, l, r; i <= m; ++i) {
		cin >> opt >> l >> r;
		if (opt == 1) modify (1, 1, n, l, r);
		else cout << query (1, 1, n, l, r)[1] << endl;
	}
}

signed main () {
	get_phi ();
	charming ();
	return 0;
}