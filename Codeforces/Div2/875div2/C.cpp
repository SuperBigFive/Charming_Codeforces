#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> tag (n + 5), cnt (n + 5), vis (n + 5);
	vector <vector <pair <int, int> > > G (n + 5);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].emplace_back (make_pair (v, i));
		G[v].emplace_back (make_pair (u, i));
	}
	queue <int> q;
	q.push (1);
	while (!q.empty ()) {
		int u = q.front ();
		q.pop ();
		vis[u] = true;
		for (auto &[v, id] : G[u]) {
			if (vis[v]) continue;
			else if (id > tag[u]) {
				tag[v] = id;
				cnt[v] = cnt[u];
				q.push (v);
			}
			else {
				cnt[v] = cnt[u] + 1;
				tag[v] = id;
				q.push (v);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = max (ans, cnt[i] + 1);
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}