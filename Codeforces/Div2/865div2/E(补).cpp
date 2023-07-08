#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e3 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <int> > adj (n + 5);
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		adj[v].emplace_back (u);
	}
	vector <int> dep (n + 5);
	queue <int> q;
	q.push (1), dep[1] = 1;
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		for (auto &v : adj[u]) {
			if (dep[v]) continue;
			dep[v] = dep[u] + 1;
			q.push (v);
		}
	}
	vector <vector <int> > same_d (n + 5);
	for (int i = 1; i <= n; ++i) {
		same_d[dep[i]].emplace_back (i);
	}
	if (same_d[0].size ()) return void (cout << "INFINITE" << endl);
	else cout << "FINITE" << endl;
	vector <int> ans;
	for (int i = 1; i <= n; ++i)
	for (int j = n; j >= i; --j)
	for (auto &k : same_d[j]) ans.emplace_back (k);
	cout << ans.size () << endl;
	for (auto &it : ans) cout << it << " ";
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}