#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

struct Edge {
	int from;
	int to;
	int nxt;
}edge[maxn << 1];
int n, m, tot, cnt, times, tail;
int dfn[maxn], low[maxn];
int head[maxn], stk[maxn];
vector <int> bcc[maxn];

void init () {
	fill (head, head + maxn, -1);
}

void add_edge (int u, int v) {
	edge[tot].from = u;
	edge[tot].to = v;
	edge[tot].nxt = head[u];
	head[u] = tot;
	++tot;
}

void tarjan (int last, int u) {
	dfn[u] = low[u] = ++times;
	int child = 0;
	stk[++tail] = u;
	for (int i = head[u], v; i != -1; i = edge[i].nxt) {
		v = edge[i].to;
		if (!dfn[v]) {
			++child;
			tarjan (i, v);
			low[u] = min (low[u], low[v]);
		}
		else if (i != (last ^ 1)) {
			low[u] = min (low[u], dfn[v]);
		}
	}
	if (last == -1 && !child) bcc[++cnt].emplace_back (u);
	else if (low[u] == dfn[u]) {
		++cnt;
		while (stk[tail] != u)
		bcc[cnt].emplace_back (stk[tail--]);
		bcc[cnt].emplace_back (stk[tail--]);
	}
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		if (u == v) continue;
		add_edge (u, v);
		add_edge (v, u);
	}
	for (int i = 1; i <= n; ++i) {
		if (dfn[i]) continue;
		tarjan (-1, i);
	}
	cout << cnt << endl;
	for (int i = 1, siz; i <= cnt; ++i) {
		cout << (siz = bcc[i].size ()) << " ";
		for (int j = 0; j < siz; ++j) {
			cout << bcc[i][j] << " \n" [j == siz - 1];
		}
	}
}

signed main () {
	charming ();
	return 0;	
}