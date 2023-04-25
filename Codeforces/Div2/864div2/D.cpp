#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m;

void init () {}

struct Node {
	int val, id;
  bool operator < (const Node& r) const {
    if (this -> val != r.val) return this -> val < r.val;
    else return this -> id > r.id;
  }
};

void dfs (vector <int> &siz, vector <int> &sum, vector <int> &a,
vector <int> &fa, vector <set <int> > &adj, vector <int> &isLeaf,
vector <set <Node> > &son, int f, int u) {
	siz[u] = 1, sum[u] = a[u];
	fa[u] = f;
	if (adj[u].size () == 1 && u != 1) {
		isLeaf[u] = 1;
		return;
	}
	for (auto &v : adj[u]) {
		if (v == f) continue;
		dfs (siz, sum, a, fa, adj, isLeaf, son, u, v);
		siz[u] += siz[v];
		sum[u] += sum[v];
		son[u].insert ({siz[v], v});
	}
}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> a (n + 5), fa (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	vector <set <int> > adj (n + 5);
	vector <set <Node> > son (n + 5);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;	
		adj[u].insert (v);
		adj[v].insert (u);
	}
	vector <int> sum (n + 5), siz (n + 5), isLeaf (n + 5);
	
	dfs (siz, sum, a, fa, adj, isLeaf, son, 0, 1);
	
	auto rotate = [&] (int y) {
		int x = (*(son[y].rbegin ())).id, z = fa[y];
		int old_sum = sum[y], old_siz = siz[y];
		fa[x] = z, fa[y] = x;
		adj[x].insert (z);
		if (adj[y].count (z)) adj[y].erase (z);
		if (adj[z].count (y)) adj[z].erase (y);
		adj[z].insert (x);
		if (adj[y].size () == 1) isLeaf[y] = 1;
		isLeaf[x] = 0;
		siz[y] -= siz[x], sum[y] -= sum[x];
		son[x].insert ({siz[y], y});
		if (son[z].count ({old_siz, y})) son[z].erase ({old_siz, y});
		if (son[y].count ({siz[x], x})) son[y].erase ({siz[x], x});
		son[z].insert ({old_siz, x});
		siz[x] = old_siz;
		sum[x] = old_sum;
		if (son[y].size () <= 0) isLeaf[y] = 1;
	};
	
	for (int i = 1, opt, x; i <= m; ++i) {
		cin >> opt >> x;
		if (opt == 1) cout << sum[x] << endl;
		else if (!isLeaf[x]) rotate (x);
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}

/*
10 9
-16 -90 -671 -314 -910548234 121155052 -359359950 83112406 -704889624 145489303
1 6
1 10
10 8
1 4
3 4
2 7
2 5
3 2
9 8

2 2
2 4
2 10
2 8
2 10
1 5
1 8
*/