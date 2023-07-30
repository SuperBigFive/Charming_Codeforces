#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <int> in (n + 5), cost (n + 5);
	vector <vector <int> > G (n + 5), revG (n + 5);
	for (int i = 1; i <= n; ++i) cin >> cost[i];
	for (int i = 1, p; i <= k; ++i) {
		cin >> p, cost[p] = 0;
	}
	for (int u = 1, m; u <= n; ++u) {
		cin >> m;
		in[u] = m;
		for (int j = 1, v; j <= m; ++j) {
			cin >> v;
			G[v].emplace_back (u);
			revG[u].emplace_back (v);
		}
	}
	
	queue <int> q;
	for (int i = 1; i <= n; ++i) if (!in[i]) q.push (i);
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		for (int v : G[u]) {
			--in[v];
			if (in[v] == 0) q.push (v);
		}
		if ((int) revG[u].size ()) {
			ll sum = 0;
			for (int v : revG[u]) sum += cost[v];
			cost[u] = min (cost[u], sum);
		}
	}
	for (int i = 1; i <= n; ++i) cout << cost[i] << " \n"[i == n];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}