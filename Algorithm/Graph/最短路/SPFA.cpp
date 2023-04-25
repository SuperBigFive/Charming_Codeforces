#include <bits/stdc++.h>
#define ll long long
#define int ll
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

bool spfa () {
	queue <int> q;
	dis[s] = 0, vis[s] = 0;
	q.push (s);
	int u;
	while (!q.empty ()) {
		u = q.front ();
		q.pop (), vis[u] = false;
		for (int i = head[u], v; i != -1; i = nxt[i]) {
			v = to[i];
			if (dis[v] > dis[u] + w[i]) {
				dis[v] = dis[u] + w[i];
				cnt[v] = cnt[u] + 1;
				if (cnt[v] >= n) return false;
				if (!vis[v]) q.push (v), vis[v] = true;
			}
		}
	}
	return true;
}

void charming () {
	init ();
	cin >> n >> m >> s;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		add_edge (u, v, w);
	}
	spfa ();
	for (int i = 1; i <= n; ++i) 
	cout << dis[i] << " \n"[i == n];
}

signed main () {
	charming ();
	return 0;
}