#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
int dp[maxn][2];
vector <int> adj[maxn];

void init () {}

void dfs (int u) {
	if (!adj[u].size ()) {
		dp[u][0] = dp[u][1] = 1;
		return;
	}
	for (auto it : adj[u]) {
		dfs (it);
		dp[u][0] = max (dp[u][0], dp[it][0] + 1);
		dp[u][1] += max (dp[it][0], dp[it][1]);
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 2, f; i <= n; ++i) {
		cin >> f;
		adj[f].emplace_back (i);
	}
	dfs (1);
	cout << max (dp[1][0], dp[1][1]) << endl;
}

signed main () {
	charming ();
	return 0;
}