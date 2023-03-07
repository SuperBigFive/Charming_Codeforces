#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <pair <int, int> > edge (m);
	vector <vector <int> > adj (n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> edge[i].first >> edge[i].second;
		adj[edge[i].first].emplace_back (edge[i].second);
	}
	vector <int> dep (n + 1, INT_MAX);
	vector <int> stk, ans (n + 1, INT_MAX);
	queue <int> q;
	q.push (1), dep[1] = 0;
	while (!q.empty ()) {
		int u = q.front ();
		stk.emplace_back (u);
		q.pop ();
		ans[u] = dep[u];
		for (auto &v : adj[u]) {
			if (dep[v] < dep[u]) ans[u] = min (ans[u], dep[v]);
			else if (dep[v] >= INT_MAX) q.push (v), dep[v] = dep[u] + 1;
		}
	}
	adj = vector <vector <int> > (n + 1);
	for (int i = 0; i < m; ++i) {
		adj[edge[i].second].emplace_back (edge[i].first);
	}
	while (!stk.empty ()) {
		int u = stk.back ();
		for (auto &v : adj[u]) if (dep[v] < dep[u])
		ans[v] = min (ans[v], ans[u]);
		stk.pop_back ();
	}
	for (int i = 1; i <= n; ++i)
	cout << ans[i] << " \n"[i == n];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}