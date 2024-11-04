#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
vector <int> adj[maxn];

void init () {}

void charming () {
	init ();
	cin >> n >> m;		
	for (int i = 1, a, b; i <= m; ++i) {
		cin >> a >> b;
		adj[a].emplace_back (b);
		adj[b].emplace_back (a);
	}
	for (int i = 1; i <= n; ++i) {
		if (!adj[i].size ()) continue;
		sort (adj[i].begin (), adj[i].end ());
	}
	for (int i = 1; i <= n; ++i) {
		cout << adj[i].size () << " ";
		for (auto it : adj[i]) cout << it << " ";
		cout << endl;
	}
}

signed main () {
	charming ();
	return 0;
}