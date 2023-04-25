#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e6 + 5;

int t, n;
ll res;
int siz[maxn], dp[maxn];
vi adj[maxn];

void init () {
	for (int i = 1; i <= n; ++i) {
		dp[i] = siz[i] = 0;
		adj[i].clear ();
	}
	res = 0;
}

int dfs (int f, int u) {
	int tmp_dp = 0;
	siz[u] = 1;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs (u, it);
		siz[u] += siz[it];
		tmp_dp = max (tmp_dp, dp[it]);
	}
	return dp[u] = tmp_dp + siz[u];
}

void charming () {
	init ();
	cin >> n;
	int u, v;
	for (int i = 1 ; i < n; ++i) {
		cin >> u >> v;
		adj[u].pb (v);
		adj[v].pb (u);
	}
	dfs (0, 1);
	cout << dp[1] << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}