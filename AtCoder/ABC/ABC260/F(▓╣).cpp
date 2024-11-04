#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxs = 3e5 + 5;
const int maxt = 3e3 + 5;

int s, t, m;
int vis[maxt][maxt];
vi adj[maxs];

void charming () {
	cin >> s >> t >> m;
	int u, v;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		for (auto it : adj[u]) {
			if (vis[it][v - s]) {
				cout << it + s << ' ' << v << ' ' << u << ' ' << vis[it][v - s] << endl;
				return;
			}
			else vis[it][v - s] = vis[v - s][it] = u;
		}
		adj[u].pb (v - s);
	}
	cout << -1 << endl;
}

signed main () {
	charming ();
	return 0;
}