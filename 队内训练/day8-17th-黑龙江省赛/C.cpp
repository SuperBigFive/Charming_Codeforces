#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
int a[maxn], dp[maxn][2];
vector <vector <int> > adj;

void init () {
	for (int i = 1; i < maxn; ++i)
	dp[i][0] = INT_MAX, dp[i][1] = 0;
}

void dfs (int f, int u) {
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs (u, it);
		if (a[it] > a[u] && dp[it][0] > a[u]) dp[u][1] = max (dp[u][1], min (a[it], dp[it][1]));
		else if (a[it] > a[u]) dp[u][1] = max (dp[u][1], dp[it][1]);
		else if (dp[it][0] > a[u]) dp[u][1] = max (dp[u][1], a[it]);
		else dp[u][1] = n + 1;
		if (a[it] < a[u] && dp[it][1] < a[u]) dp[u][0] = min (dp[u][0], max (a[it], dp[it][0]));
		else if (a[it] < a[u]) dp[u][0] = min (dp[u][0], dp[it][0]);
		else if (dp[it][1] < a[u]) dp[u][0] = min (dp[u][0], a[it]);
		else dp[u][0] = -1;
	}
}

void charming () {
	init ();	
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	adj.resize (n + 1);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs (0, 1);
	if (dp[1][0] < 0 && dp[1][1] > n) cout << "NO" << endl;
	else cout << "YES" << endl;
}

signed main () {
	charming ();
	return 0;
}