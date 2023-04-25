#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e6 + 5;

int t, n, m, tot;
vector <int> st (N);
vector <map <string, int> > adj (N);

void init () {
	for (int i = 0; i <= tot; ++i)
	st[i] = 0, adj[i].clear ();
	tot = 0;
}

void charming () {
	init ();
	cin >> n >> m;
	string path, name;
	for (int i = 1, cur; i <= n + m; ++i) {
		cin >> path, path.push_back ('/');
		cur = 0, name.clear ();
		for (int j = 0; j < path.size (); ++j) {
			if (path[j] == '/') {
				if (!adj[cur].count (name)) {
					adj[cur][name] = ++tot;
				}
				cur = adj[cur][name];
				if (j == path.size () - 1) {
					if (i <= n) st[cur] = 1;
					else st[cur] = 0;
				}
				name.clear ();
			}
			else name.push_back (path[j]);
		}
	}
	int res = 0;
	auto dfs = [&] (auto && me, int u) -> pair <bool, int> {
		if (!adj[u].size ()) return {st[u], st[u]};
		bool ok = true;
		int res = 0;
		for (auto &it : adj[u]) {
			auto v = it.second;
			auto [nst, nres] = me (me, v);
			ok &= nst, res += nres;
		}
		if (ok && u) return {ok, 1};
		else return {ok, res};
	};
	cout << dfs (dfs, 0).second << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}