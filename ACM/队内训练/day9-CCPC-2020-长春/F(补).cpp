#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 1e6 + 5;
const int LEN = 20;

int n, pval;
ll res = 0;
vector <int> a, b, siz, son;
vector <vector <int> > adj;
vector <vector <pair <int, int> > > cnt;

void init () {res = 0;}

void dfs (int f, int u) {
	for (auto &v : adj[u]) {
		if (v == f) continue;
		dfs (u, v);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void modify (int id, int val, int c) {
	for (int i = 0; i < LEN; ++i) {
		if ((id >> i) & 1) cnt[val][i].second += c;
		else cnt[val][i].first += c;
	}
}

void cal (int f, int u) {
	b.emplace_back (u);
	int target = pval ^ a[u];
	if (target < N) {
		for (int i = 0; i < LEN; ++i) {
			if ((u >> i) & 1)
			res += (ll) cnt[target][i].first * (1 << i);
			else res += (ll) cnt[target][i].second * (1 << i);
		}
	}
	for (auto &v : adj[u]) {
		if (v == f) continue;
		cal (u, v);
	}
}

void del (int f, int u) {
	modify (u, a[u], -1);
	for (auto &v : adj[u]) {
		if (v == f) continue;
		del (u, v);
	}
}

void dsu (int f, int u, int st) {
	for (auto &v : adj[u]) {
		if (v == f || v == son[u]) continue;
		dsu (u, v, 0);
	}
	if (son[u]) dsu (u, son[u], 1);
	pval = a[u];
	for (auto &v : adj[u]) {
		if (v == f || v == son[u]) continue;
		cal (u, v);
		for (auto &vv : b) modify (vv, a[vv], 1);
		b.clear ();
	}
	modify (u, a[u], 1);
	if (!st) del (f, u);
}

void charming () {
	init ();
	cin >> n;
	a.resize (n + 1), siz.resize (n + 1, 1);
	son.resize (n + 1), adj.resize (n + 1);
	cnt.resize (N, vector <pair <int, int> > (LEN));
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs (0, 1);
	dsu (0, 1, 1);
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}