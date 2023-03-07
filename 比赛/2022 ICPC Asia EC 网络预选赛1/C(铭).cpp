#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n, res;
int siz[maxn];
vector <int> adj[maxn];

void init () {
	for (int i = 1; i <= n; ++i) adj[i].clear (), siz[i] = 0;
	res = 0;
}

void dfs (int f, int u) {
	siz[u] = adj[u].size () - 1;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs (u, it);
	}
	if (u == 1) res += adj[u].size () + (adj[u].size () == 1);
	else if (siz[u]) res += siz[u] - 1;
}
		
void charming () {
	init ();
	cin >> n;	
	if (n == 1) {
		cout << 1 << endl;
		return;
	}
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs (0, 1);
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}