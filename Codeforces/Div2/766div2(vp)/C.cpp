#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct Edge {
	int to;
	int nxt;
	int wet;
}edge[N << 1];
int t, n, tot;
int head[N], in[N];

void init () {
	for (int i = 0; i <= tot; ++i)
	edge[i].to = edge[i].nxt = edge[i].wet = 0;
	for (int i = 1; i <= n; ++i) head[i] = 0, in[i] = 0;
	tot = 0;
}

void add_edge (int u, int v) {
	edge[++tot].to = v;
	edge[tot].nxt = head[u];
	head[u] = tot;
}

void dfs (int f, int u, int st) {
	for (int i = head[u]; i > 0; i = edge[i].nxt) {
		if (edge[i].to == f) continue;
		edge[i].wet = (st ? 2 : 3);
		dfs (u, edge[i].to, st ^ 1);
	}
}

void charming () {
	init ();
	cin >> n;
	bool ok = true;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		add_edge (u, v);
		add_edge (v, u);
		++in[u], ++in[v];
		if (in[u] > 2 || in[v] > 2) ok = false;
	}
	if (!ok) {
		cout << -1 << endl;
		return;
	}
	int be = 1;
	while (in[be] > 1) ++be;
	dfs (0, be, 0);
	for (int i = 1; i < n; ++i) {
		if (edge[i << 1].wet > 0) cout << edge[i << 1].wet << " ";
		else cout << edge[(i << 1) - 1].wet << " ";
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}