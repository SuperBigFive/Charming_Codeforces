#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int n, depest = -1, id;
vi adj[maxn];
void init () {
	
}

void dfs (int fa, int u, int dep) {
	if (dep > depest) {
		depest = dep;
		id = u;
	}
	for (auto it : adj[u]) {
		if (it == fa) continue;
		dfs (u, it, dep + 1);
	}
}

void charming () {
	cin >> n;
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[u].pb (v);
		adj[v].pb (u);
	}
	dfs (0, 1, 1);
	dfs (0, id, 1);
	cout << depest - 1 << endl;
}

signed main () {
	charming ();
	return 0;
}