#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pii pair <int, int> 
using namespace std;
const int maxn = 2e3 + 5;
const int maxm = 1e4 + 5;

int n, m, c, tot, res;
int to[maxm], nxt[maxm];
int wet[maxm], head[maxm];
int dis[maxn][maxn], vis[maxn][maxn];

void init () {
	res = INT_MAX;
	fill (head, head + maxm, -1);
}

void add_edge (int u, int v, int w) {
	to[tot] = v;
	nxt[tot] = head[u];
	wet[tot] = w;
	head[u] = tot++;
}

void dij (int s) {
	priority_queue <pii, vector <pii>, greater <pii> > pq;
	pq.push (make_pair (0, s));
	for (int i = 1; i <= n; ++i) dis[s][i] = INT_MAX;
	while (!pq.empty ()) {
		auto [d, u] = pq.top ();
		pq.pop ();
		if (vis[s][u]) continue;
		vis[s][u] = true;
		for (int i = head[u], v; i != -1; i = nxt[i]) {
			v = to[i];
			if (v == s) res = min (res, d + wet[i]);
			else if (vis[s][v]) continue;
			else if (dis[s][v] > d + wet[i]) {
				dis[s][v] = d + wet[i];
				pq.push (make_pair (dis[s][v], v));
			}
		}
	}
}

void charming () {
	init ();	
	cin >> n >> m >> c;
	int mn = INT_MAX;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		add_edge (u, v, w);
		mn = min (mn, w);
	}
	for (int i = 1; i <= n; ++i) dij (i);
	if (res > c) cout << (c >= mn ? 1 : 0) << endl;
	else cout << 2 << endl;
}

signed main () {
	charming ();
	return 0;
}