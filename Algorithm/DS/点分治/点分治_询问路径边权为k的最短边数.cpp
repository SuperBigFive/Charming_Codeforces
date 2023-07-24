#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 1e6 + 5;

int n, k, ans;
int siz[N], vis[N], dep[M];

void init () {
	ans = INT_MAX;
	for (int i = 0; i < M; ++i) dep[i] = INT_MAX;	
}

void Get_root (int f, int u, int remain, int &mx, int &rt,
vector <vector <pair <int, int> > > &G) {
	siz[u] = 1;
	int mx_siz = -1;
	for (auto [v, w] : G[u]) {
		if (v == f || vis[v]) continue;
		Get_root (u, v, remain, mx, rt, G);
		mx_siz = max (mx_siz, siz[v]);
		siz[u] += siz[v];
	}
	mx_siz = max (mx_siz, remain - siz[u]);
	if (mx_siz < mx) mx = mx_siz, rt = u;
}

void DFS (int f, int u, int d, int sum, vector <pair <int, int> > &stk, 
vector <vector <pair <int, int> > > &G) {
	siz[u] = 1;
	stk.emplace_back (make_pair (sum, d));
	if (sum < k && dep[k - sum] < INT_MAX) ans = min (ans, d + dep[k - sum]);
	for (auto [v, w] : G[u]) {
		if (v == f || vis[v]) continue;
		DFS (u, v, d + 1, sum + w, stk, G);
		siz[u] += siz[v];
	}
}

void Calc (int u, vector <vector <pair <int, int> > > &G) {
	siz[u] = 1;
	int tail = 0;
	vector <pair <int, int> > stk;
	for (auto [v, w] : G[u]) {
		if (vis[v]) continue;
		DFS (u, v, 1, w, stk, G);
		siz[u] += siz[v];
		while (tail < (int) stk.size ()) {
			auto [val, d] = stk[tail++];
			if (val < M) dep[val] = min (dep[val], d);
		}
	}
	if (dep[k] < INT_MAX) ans = min (ans, dep[k]);
	while (!stk.empty ()) {
		if (stk.back ().first < M) dep[stk.back ().first] = INT_MAX;
		stk.pop_back ();
	}
}

void Divide (int u, vector <vector <pair <int, int> > > &G) {
	vis[u] = 1;
	Calc (u, G);
	for (auto [v, w] : G[u]) {
		if (vis[v]) continue;
		int mx = INT_MAX, rt = -1;
		Get_root (0, v, siz[v], mx, rt, G);
		Divide (rt, G);
	}
}

void charming () {
	init ();
	cin >> n >> k;
	vector <vector <pair <int, int> > > G (n + 5);
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		++u, ++v;
		G[u].emplace_back (make_pair (v, w));
		G[v].emplace_back (make_pair (u, w));
	}
	int mx = INT_MAX, rt = -1;
	Get_root (0, 1, n, mx, rt, G);
	Divide (rt, G);
	if (ans >= INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}