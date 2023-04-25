#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1), siz (n + 1, 1);
	vector <vector <int> > adj (n + 1);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	cin >> m;
	vector <int> prim (m), wet;
	for (auto &it : prim) cin >> it;
	while (prim.size () < n - 1) prim.emplace_back (1);
	auto dfs = [&] (auto && me, int f, int u) -> void {
		for (auto &v : adj[u]) {
			if (v == f) continue;
			me (me, u, v);
			siz[u] += siz[v];
			wet.emplace_back ((n - siz[v]) * siz[v]);
		}
	};
	dfs (dfs, 0, 1);
	sort (prim.begin (), prim.end ());
	sort (wet.begin (), wet.end ());
	for (int i = n - 1; i < prim.size (); ++i)
	prim[n - 2] = (prim[n - 2] * (prim[i] % mod)) % mod;
	ll res = 0;
	for (int i = 0; i < n - 1; ++i)
	res = (res + (prim[i] * (wet[i] % mod)) % mod) % mod;
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}