#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;

int n, m, tot;
int dis[maxn], cnt[maxn];
int to[maxn], nxt[maxn];
int wet[maxn], head[maxn];
bool vis[maxn];

void init () {
	fill (head, head + maxn, -1);
	fill (dis, dis + maxn, INT_MAX);
}

void add_edge (int u, int v, int w) {
	to[tot] = v;
	nxt[tot] = head[u];
	wet[tot] = w;
	head[u] = tot++;
}

bool spfa () {
	queue <int> q;
	q.push (0), dis[0] = 0;
	int u;
	while (!q.empty ()) {
		u = q.front ();
		q.pop (), vis[u] = false;
		for (int i = head[u], v; i != -1; i = nxt[i]) {
			v = to[i];
			if (dis[v] > dis[u] + wet[i]) {
				dis[v] = dis[u] + wet[i];
				cnt[v] = cnt[u] + 1;
				if (cnt[v] > n) return false;
				if (!vis[v]) vis[v] = true, q.push (v);
			}
		}
	}
	return true;
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
	add_edge (0, i, 0);
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		add_edge (v, u, w);
	}
	if (!spfa ()) cout << "NO" << endl;
	else {
		for (int i = 1; i <= n; ++i)
		cout << dis[i] << " \n"[i == n];
	}
}

signed main () {
	charming ();
	return 0;
}
