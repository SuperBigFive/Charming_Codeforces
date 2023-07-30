#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> siz (n + 5, 1);
	vector <vector <int> > G (n + 5);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].emplace_back (v);
		G[v].emplace_back (u);
	}
	ll ans = 0;
	
	auto DFS = [&] (auto && me, int f, int u) -> void {
		int c1 = 0, c2 = 0, c3 = 0;
		for (int v : G[u]) {
			if (v == f) continue;
			me (me, u, v);
			siz[u] += siz[v];
			c3 += c2 * siz[v];
			c2 += c1 * siz[v];
			c1 += siz[v];
		}
		ans += c3 + c2 * (n - siz[u]);
	};
	
	DFS (DFS, 0, 1);	
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}