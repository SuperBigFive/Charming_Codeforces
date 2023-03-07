#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N  = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n), cnt (N);
	vector <vector <int> > adj (N);
	for (auto &it : a) {
		cin >> it;	
		++cnt[it];
	}
	vector <int> ans = cnt, vis (N);
	for (int i = 1; i < N; ++i) {
		if (!cnt[i]) continue;
		for (int j = i + i; j < N; j += i) {
			if (!cnt[j]) continue;
			adj[i].emplace_back (j);
		}
	}
	auto dfs = [&] (auto && me, int u) -> void {
		vis[u] = true;
		for (auto &v : adj[u]) {
			if (!vis[v]) me (me, v);
			ans[u] = max (ans[u], cnt[u] + ans[v]);
		}
	};
	for (int i = 1; i < N; ++i) {
		if (!cnt[i] || vis[i]) continue;
		dfs (dfs, i);
	}
	int mx = -1;
	for (int i = 1; i < N; ++i) mx = max (mx, ans[i]);
	cout << n - mx << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}