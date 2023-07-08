#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e5 + 5;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> ins (n);
	vector <vector <int> > G (n);
	for (int i = 1, p; i < n; ++i) {
		cin >> p, --p;
		G[p].emplace_back (i);
	}
	for (int i = 0, x, y; i < m; ++i) {
		cin >> x >> y, --x;
		ins[x] = max (ins[x], y);
	}
	multiset <int> mx;
	int ans = 0;
	
	auto DFS = [&] (auto && me, int u, int dep) -> void {
		if (ins[u] > 0) mx.insert (dep + ins[u]);
		if ((int) mx.size () && dep <= (*mx.rbegin ())) ++ans;
		for (int v : G[u]) {
			me (me, v, dep + 1);
		}
		if (ins[u] > 0) mx.erase (mx.find (dep + ins[u]));
	};
	
	DFS (DFS, 0, 0);
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}