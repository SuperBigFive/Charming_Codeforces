#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e5 + 5;

int n, k, m;

void init () {}

void charming () {
	init ();
	cin >> n >> k >> m;
	vector <int> in (n + 5);
	vector <vector <int> > adj (n + 5), id (n + 5);
	for (int i = 1, a, b; i <= m; ++i) {
		cin >> a >> b;
		adj[a].emplace_back (b);
		adj[b].emplace_back (a);
		++in[b];
	}
	for (int i = 1, c; i <= n * k; ++i) {
		cin >> c, id[c].emplace_back (i);
	}
	queue <int> q;
	for (int i = 1; i <= n; ++i) if (!in[i]) q.push (i);
	vector <int> ans (n * k + 5);
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		for (auto v : adj[u]) {
			--in[v];
			if (!in[v]) q.push (v);
		}
		for (int i = 0; i < k; ++i) 
		ans[id[u][i]] = i + 1;
	}
	for (int i = 1; i <= n * k; ++i) 
	cout << ans[i] << " \n"[i == n * k];
}

signed main () {
	charming ();
	return 0;
}