#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
int st[maxn];
pair <int, int> dp[maxn][2];
vector <vector <int> > adj;

void init () {}

bool operator > (pair <int, int> &a, pair <int, int> &b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

void dfs (int f, int u) {
	pair <int, int> tmp;
	dp[u][0].second = 1;
	dp[u][1].first = 1;
	dp[u][1].second = adj[u].size ();
	for (auto &it : adj[u]) {
		if (it == f) continue;
		dfs (u, it);
		if (dp[it][0] > dp[it][1])
		tmp = dp[it][0];
		else tmp = dp[it][1];
		dp[u][0].first += tmp.first;
		dp[u][0].second += tmp.second;
		dp[u][1].first += dp[it][0].first;
		dp[u][1].second += dp[it][0].second;
	}
}

void get_st (int f, int u) {
	for (auto &it : adj[u]) {
		if (it == f) continue;
		if (st[u] == 1) st[it] = 0;
		else st[it] = dp[it][1] > dp[it][0];
		get_st (u, it);
	}
}

void charming () {
	init ();
	cin >> n;	
	adj.resize (n + 1);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	if (n == 2) {
		cout << "2 2" << endl;
		cout << "1 1" << endl;
		return;
	}
	dfs (0, 1);
	pair <int, int> res;
	if (dp[1][0] > dp[1][1]) res = dp[1][0];
	else res = dp[1][1];
	st[1] = dp[1][1] > dp[1][0];
	get_st (0, 1);
	cout << res.first << " " << res.second << endl;
	for (int i = 1; i <= n; ++i) {
		if (st[i]) cout << adj[i].size () << " \n"[i == n];
		else cout << 1 << " \n"[i == n];
	}
}

signed main () {
	charming ();
	return 0;
}