#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;
const int M = 2e7 + 5;

int n, k, rt, mx, ans;
int vis[N], siz[N];
vector <pair <int, int> > adj[N];

void init () {}

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
	vector <int> total_stk (1, 0);
	for (auto &[v, w] : adj[u]) {
		if (vis[v]) continue;
		vector <int> stk;
		dfs (u, v, w, 1, stk);
		vector <int> nstk;
		sort (stk.begin (), stk.end ());
		int p = 0, q = 0;
		while (p < total_stk.size () || q < stk.size ()) {
			if (q >= stk.size () || (p < total_stk.size ()
			&& total_stk[p] <= stk[q])) nstk.emplace_back (total_stk[p++]);
			else nstk.emplace_back (stk[q++]);
		}
		for (p = 0, q = stk.size () - 1; p < total_stk.size (); ++p) {
			while (q >= 0 && stk[q] + total_stk[p] > k) --q;
			ans += q + 1;
		}
		total_stk = nstk;
	}
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
	cin >> n;
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back (make_pair (v, w));
		adj[v].emplace_back (make_pair (u, w));
	}
	cin >> k;
	rt = 0, mx = LLONG_MAX;
	Get_root (0, 1, n);
	Divide (rt);
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}