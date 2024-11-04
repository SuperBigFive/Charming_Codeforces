#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m, k;
int dis[maxn];
pair <pair <int, int>, int> G[maxn];

void charming () {
	cin >> n >> m >> k;
	for (int i = 1, a, b, c; i <= m; ++i) {
		cin >> a >> b >> c;
		G[i] = make_pair (make_pair (a, b), c);
	}
	fill (dis + 1, dis + 1 + n, LLONG_MAX - INT_MAX);
	dis[1] = 0;
	for (int i = 1, e; i <= k; ++i) {
		cin >> e;
		auto [it, w] = G[e];
		auto [u, v] = it;
		dis[v] = min (dis[v], dis[u] + w);
	}
	if (dis[n] == LLONG_MAX - INT_MAX) cout << -1 << endl;
	else cout << dis[n] << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}