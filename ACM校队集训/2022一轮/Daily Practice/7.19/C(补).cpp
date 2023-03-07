#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e5 + 5;

int n, m;
int c[50], w[50], path[50], dp[50], res[50];
int vis[50];

void init () {
	
}

void add (ll u, ll v) {
	path[u] = path[u] | ((ll)1 << v);
}

void dfs (int fa, int now) {
	dp[now] = dp[fa];
	if (!vis[c[now]]) dp[now] += w[c[now]];
	res[now] = max (res[now], dp[now]);
	++vis[c[now]];
	for (int i = now + 1; i <= n; ++i) {
		if (path[now] & ((ll)1 << i)) {
			dfs (now, i);
			--vis[c[i]];
		}
	}
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}
	ll u, v;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		add (u, v);
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (path[i] & ((ll) 1 << k) && path[k] & ((ll) 1 << j) && path[i] & ((ll) 1 << j))
				path[i] ^= ((ll) 1 << j);
			}
		}
	}
	dfs (0, 1);
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}