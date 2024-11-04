#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pii pair <int, int> 
using namespace std;
const int maxn = 4e5 + 5;

int n, m, k;
int dis[maxn];
bool vis[maxn];
vector <int> adj[maxn];

void init () {fill (dis, dis + maxn, INT_MAX);}

void bfs () {
	queue <int> q;
	int cur;
	q.push (1);
	dis[1] = 0;
	vis[1] = true;
	while (!q.empty ()) {
		cur = q.front ();
		q.pop ();
		for (auto it : adj[cur]) {
			if (vis[it]) continue;
			dis[it] = dis[cur] + 1;
			if (abs (it - cur) == n) --dis[it];
			vis[it] = true;
			q.push (it);
		}
	}
}
		
void charming () {
	init ();
	cin >> n >> m >> k;
	for (int i = 1, u, v, a; i <= m; ++i) {
		cin >> u >> v >> a;
		u += (a ^ 1) * n;
		v += (a ^ 1) * n;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	for (int i = 1, s; i <= k; ++i) {
		cin >> s;
		adj[s].emplace_back (s + n);
		adj[s + n].emplace_back (s);
	}
	bfs ();
	ll res = min (dis[n], dis[n << 1]);
	if (res >= INT_MAX) res = -1;
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}