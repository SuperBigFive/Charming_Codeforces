#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;

int n, rt, mx;
int col[N], col_siz[N], col_vis[N];
int ans[N], tree_siz[N], tree_vis[N];
vector <int> adj[N];

void init () {}

void Get_rt (int &rt, int &mx, int f, int u, int total) {
	int mx_siz = 0, f_siz = total - 1;
	tree_siz[u] = 1;
	for (auto &v : adj[u]) {
		if (v == f || tree_vis[v]) continue;
		Get_rt (rt, mx, u, v, total);
		tree_siz[u] += tree_siz[v];
		f_siz -= tree_siz[v];
		mx_siz = max (mx_siz, tree_siz[v]);
	}
	mx_siz = max (mx_siz, f_siz);	
	if (mx > mx_siz) mx = mx_siz, rt = u;
}

void dfs (int sum, int f, int u, int total, vector <pair <int, int> > &ncol_siz) {
	tree_siz[u] = 1;
	bool ok = false;
	if (!col_vis[col[u]]) {
		sum += total - col_siz[col[u]];
		col_vis[col[u]] = 1;
		ok = true;
	}
	ans[u] += sum;
	for (auto &v : adj[u]) {
		if (v == f || tree_vis[v]) continue;
		dfs (sum, u, v, total, ncol_siz);
		tree_siz[u] += tree_siz[v];
	}
	if (ok) {
		col_vis[col[u]] = 0;
		ncol_siz.emplace_back (make_pair (col[u], tree_siz[u]));
	}
}

void Calc (int f, int u) {
	int sum = 1, total = 1;
	vector <int> v_stk, col_stk;
	vector <pair <int, int> > ncol_siz;
	col_vis[col[u]] = 1, ans[u] += 1;
	for (auto &v : adj[u]) {
		if (v == f || tree_vis[v]) continue;
		v_stk.emplace_back (v);
		dfs (sum, u, v, total, ncol_siz);
		sum += tree_siz[v], total += tree_siz[v], ans[u] += tree_siz[v];
		for (auto &[c, siz] : ncol_siz) {
			col_stk.emplace_back (c);
			sum += siz, col_siz[c] += siz, ans[u] += siz;
		}
		ncol_siz.clear ();
	}
	for (auto &c : col_stk) col_siz[c] = 0;
	col_stk.clear ();
	sum = 0, total = 0;
	while (v_stk.size () > 0) {
		auto v = v_stk.back ();
		v_stk.pop_back ();
		dfs (sum, u, v, total, ncol_siz);
		sum += tree_siz[v], total += tree_siz[v];
		for (auto &[c, siz] : ncol_siz) {
			col_stk.emplace_back (c);
			sum += siz, col_siz[c] += siz;
		}
		ncol_siz.clear ();
	}
	for (auto &c : col_stk) col_siz[c] = 0;
	col_siz[col[u]] = col_vis[col[u]] = 0;
}

void Divide (int u) {
	tree_vis[u] = 1;
	Calc (0, u);
	for (auto &v : adj[u]) {
		if (tree_vis[v]) continue;
		Get_rt (rt = 0, mx = N, u, v, tree_siz[v]); 
		Divide (v);
	}
}

void charming () {
	init ();
	cin >> n;	
	for (int i = 1; i <= n; ++i) cin >> col[i];
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	Get_rt (rt = 0, mx = N, 0, 1, n);
	Divide (rt);
	for (int i = 1; i <= n; ++i) cout << ans[i] << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}