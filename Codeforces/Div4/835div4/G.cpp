#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, a, b;
vector <int> adj[maxn], wet[maxn];
set <int> Xora, Xorb;

void init () {
	Xora.clear (), Xorb.clear ();
	for (int i = 0; i <= n; ++i)
	adj[i].clear (), wet[i].clear ();
}

void dfs (int f, int u, int st, int XOR) {
	if (!st) {
		if (u == b) return;
		Xora.insert (XOR);
	}
	else if (u != b) Xorb.insert (XOR);
	for (int i = 0, v; i < adj[u].size (); ++i) {
		v = adj[u][i];
		if (v == f) continue;
		dfs (u, v, st, XOR ^ wet[u][i]);
	}
}

void charming () {
	init ();
	cin >> n >> a >> b;
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
		wet[u].emplace_back (w);
		wet[v].emplace_back (w);
	}
	dfs (0, a, 0, 0);
	dfs (0, b, 1, 0);
	for (auto it : Xora) {
		if (Xorb.count (it)) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}