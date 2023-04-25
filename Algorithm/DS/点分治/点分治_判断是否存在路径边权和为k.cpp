#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;
const int M = 2e7 + 5;

int n, m, rt, mx;
int vis[N], siz[N], rem[M], ans[N], query[N];
vector <pair <int, int> > adj[N];

void init () {rem[0] = 1;}

void Get_root (int f, int u, int total) {
	int mx_siz = 0, f_siz = total - 1;
	siz[u] = 1;
	for (auto &[v, w] : adj[u]) {
		if (vis[v] || v == f) continue;
		Get_root (u, v, total);
		mx_siz = max (mx_siz, siz[v]);
		siz[u] += siz[v];
		f_siz -= siz[v];
	}
	mx_siz = max (mx_siz, f_siz);
	if (mx_siz < mx) rt = u, mx = mx_siz;
}

void dfs (int f, int u, int dis, int k, vector <int> &stk) {
	siz[u] = 1;
	stk.emplace_back (dis);
	for (auto &[v, w] : adj[u]) {
		if (v == f || vis[v]) continue;
		dfs (u, v, dis + w, k, stk);
		siz[u] += siz[v];
	}
}

void Calc (int u) {
	vector <int> total_stk;
	for (auto &[v, w] : adj[u]) {
		if (vis[v]) continue;
		vector <int> stk;
		dfs (u, v, w, 1, stk);
		for (auto dis : stk) {
			for (int i = 1; i <= m; ++i) {
				if (ans[i]) continue;
				else if (dis <= query[i] && rem[query[i] - dis]) ans[i] = 1;
			}
		}
		for (auto dis : stk) ++rem[dis], total_stk.emplace_back (dis);
	}
	for (auto dis : total_stk) --rem[dis];
}

void Divide (int u) {
	vis[u] = 1;
	Calc (u);
	for (auto &[v, w] : adj[u]) {
		if (vis[v]) continue;
		rt = 0, mx = LLONG_MAX;
		Get_root (0, v, siz[v]);
		Divide (rt);
	}
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back (make_pair (v, w));
		adj[v].emplace_back (make_pair (u, w));
	}
	rt = 0, mx = LLONG_MAX;
	Get_root (0, 1, n);
	for (int i = 1; i <= m; ++i) {
		cin >> query[i];
	}
	Divide (rt);
	for (int i = 1; i <= m; ++i)
	cout << (ans[i] ? "AYE" : "NAY") << endl;
}

signed main () {
	charming ();
	return 0;
}