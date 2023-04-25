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

int n, res;
int dp1[maxn], dp2[maxn];
vi adj[maxn];

int dfs (int fa, int u) {
	vi son_dp;
	son_dp.pb (0);
	for (auto it : adj[u]) {
		if (it == fa) continue;
		son_dp.pb (dfs (u, it));
	}
	sort (son_dp.begin (), son_dp.end (), [] (int x, int y) {
		return x > y;
	});
	if (son_dp.size () > 1) res = max (res, son_dp[0] + son_dp[1]);
	else res = max (res, son_dp[0]);
	return son_dp[0] + 1;
}

void charming () {
	cin >> n;
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[u].pb (v);
		adj[v].pb (u);
	}
	dfs (0, 1);
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}