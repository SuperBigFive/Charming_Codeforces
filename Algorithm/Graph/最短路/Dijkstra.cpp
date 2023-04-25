#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pii pair <int, int> 
using namespace std;
const int maxn = 5e5 + 5;

int n, m, s, tot;
int to[maxn], nxt[maxn], w[maxn], head[maxn];
int cnt[maxn], dis[maxn];
bool vis[maxn];

void init () {
	fill (head, head + maxn, -1);
	fill (dis, dis + maxn, INT_MAX);
}

void add_edge (int uu, int vv, int ww) {
	to[tot] = vv;
	nxt[tot] = head[uu];
	w[tot] = ww;
	head[uu] = tot++;
}

void dijkstra () {
	priority_queue <pii, vector <pii>, greater <pii> > pq;
	pq.push (make_pair (0, s));
	dis[s] = 0;
	while (!pq.empty ()) {
		auto [d, u] = pq.top ();
		pq.pop ();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = head[u], v; i != -1; i = nxt[i]) {
			v = to[i];
			if (vis[v]) continue;
			if (dis[v] > dis[u] + w[i]) {
				dis[v] = dis[u] + w[i];
				pq.push (make_pair (dis[v], v));
			}
		}
	}
}

void charming () {
	init ();
	cin >> n >> m >> s;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		add_edge (u, v, w);
	}
	dijkstra ();
	for (int i = 1; i <= n; ++i) 
	cout << dis[i] << " \n"[i == n];
}

signed main () {
	charming ();
	return 0;
}