#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 4e5 + 5;

struct Edge {
	int to;
	int nxt;
	int wet;
	int path_inc, path_dec;
}edge[maxn];

int n, tot, res;
int head[maxn];

void init () {fill (head, head + maxn, -1);}

void add_edge (int u, int v, int w) {
	edge[tot].to = v;
	edge[tot].nxt = head[u];
	edge[tot].wet = w;
	edge[tot].path_inc = 0;
	edge[tot].path_dec = 0;
	head[u] = tot++;
}

void dfs (int f, int u) {
	vector <Edge> adj;
	adj.clear ();
	for (int i = head[u], v; i != -1; i = edge[i].nxt) {
		v = edge[i].to;
		if (v == f) continue;
		dfs (u, v);
		edge[i].path_dec = 1;
		edge[i].path_inc = 1;
		for (int j = head[v], vv; j != -1; j = edge[j].nxt) {
			vv = edge[i].to;
			if (vv == u) continue;
			if (edge[i].wet < edge[j].wet) 
			edge[i].path_inc += edge[j].path_inc;
			if (edge[i].wet > edge[j].wet) 
			edge[i].path_dec += edge[j].path_dec;
		}
		adj.emplace_back (edge[i]);
	}
	if (!adj.size ()) return;
	sort (adj.begin (), adj.end (), [] (Edge &x, Edge &y) {
		return x.wet < y.wet;
	});
	int remain = 0;
	for (auto it : adj) res += it.path_inc + it.path_dec, remain += it.path_inc;
	for (int i = 0, j = 0; i < adj.size (); ++i) {
		j = max (i, j);
		while (j < adj.size () && adj[j].wet <= adj[i].wet) 
		remain -= adj[j].path_inc, ++j;  
		if (j >= adj.size ()) break;
		res += adj[i].path_dec * remain;
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		add_edge (u, v, w);
		add_edge (v, u, w);
	}
	dfs (0, 1);
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}