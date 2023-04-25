#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <vector <int> > adj (n + 5);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	queue <int> q;
	q.push (1);
	int st = 1;
	vector <bool> vis (n + 5);
	vis[1] = true;
	while (!q.empty ()) {
		queue <int> nq;
		while (!q.empty ()) {
			int u = q.front ();
			q.pop ();
			for (auto &v : adj[u]) {
				if (vis[v]) continue;
				vis[v] = true;
				nq.push (v);
			}
		}
		if (nq.size () & 1) st ^= 1;
		q = nq;
	}
	if (st) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}