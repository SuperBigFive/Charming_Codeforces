#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;
int pre[maxn];
bool vis[maxn];
pair <int, int> adj[maxn];
set <int> s;
vector <int> edge;

void init () {}

int find (int x) {
	if (x == pre[x]) return x;
	return pre[x] = find (pre[x]);
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		adj[i].first = u, adj[i].second = v;
	}
	while (true) {
		s.clear (), edge.clear ();
		fill (vis + 1, vis + 1 + m, false);
		for (int i = 1; i <= n; ++i) pre[i] = i;
		int cnt = 1;
		int u, v, fu, fv, id;
		while (cnt <= m) {
			id = ((rand () << 15) + rand ()) % m + 1;
			if (vis[id]) continue;
			++cnt, vis[id] = true;
			u = adj[id].first, v = adj[id].second;
			fu = find (u), fv = find (v);
			if (fu == fv) edge.emplace_back (id);
			else pre[fu] = fv;
		}
		for (auto it : edge) {
			u = adj[it].first, v = adj[it].second;
			s.insert (u), s.insert (v);
		}
		if (m == n + 2 && s.size () == 3) continue;
		else break;
	}
	fill (vis + 1, vis + 1 + m, false);
	for (auto it : edge) vis[it] = true;
	for (int i = 1; i <= m; ++i) {
		if (vis[i]) cout << 0;
		else cout << 1;
	}
	cout << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	srand (time (0));
	cin >> t;
	while (t--) charming ();
	return 0;
}