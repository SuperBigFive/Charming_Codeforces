//tarjan求点双连通分量
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

struct Edge {
	int from;
	int to;
	int nxt;
}edge[maxn << 1];
int n, m, tot, times, cnt, tail;
int dfn[maxn], low[maxn];
int head[maxn], stk[maxn];
bool isCut[maxn];
set <int> bcc[maxn];

void init () {
	tot = times = cnt = tail = 0;
}

void add_edge (int u, int v) {
	edge[++tot].from = u;
	edge[tot].to = v;
	edge[tot].nxt = head[u];
	head[u] = tot;
}

void tarjan (int f, int u) {
	dfn[u] = low[u] = ++times;
	int child = 0;
	for (int i = head[u], v; i; i = edge[i].nxt) {
		v = edge[i].to;
		if (!dfn[v]) {
			++child;
			stk[++tail] = i;
			tarjan (u, v);
			low[u] = min (low[u], low[v]);
			if (low[v] >= dfn[u]) {
				++cnt;
				isCut[u] = true;
				while (true) {
					int j = stk[tail--];
					bcc[cnt].insert (edge[j].from);
					bcc[cnt].insert (edge[j].to);
					if (edge[j].from == u 
					&& edge[j].to == v) break;
				}
			}
		}
		else if (dfn[v] < dfn[u] && v != f) {
			stk[++tail] = i;
			low[u] = min (low[u], dfn[v]);
		}
	}
	if (!f && child == 1) isCut[u] = false;
	if (!f && !child) bcc[++cnt].insert (u);
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
		tarjan (0, i);
	}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; ++i) {
		cout << bcc[i].size () << " ";
		for (auto it : bcc[i])
		cout << it << " ";
		cout << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}

/*
//tarjan求点双连通分量(dfn把点入栈的做法，少了个log)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;

int n, m, tot, cnt, times, tail;
int dfn[maxn], low[maxn], stk[maxn];
int from[maxn], to[maxn], nxt[maxn], head[maxn];
vector <int> bcc[maxn];

void init () {
	fill (head, head + maxn, -1);
}

void add_edge (int u, int v) {
	from[tot] = u;
	to[tot] = v;
	nxt[tot] = head[u];
	head[u] = tot++;
}

void tarjan (int last, int u) {
	dfn[u] = low[u] = ++times;
	int child = 0;
	stk[++tail] = u;
	for (int i = head[u], v; i != -1; i = nxt[i]) {
		v = to[i];
		if (!dfn[v]) {
			++child;
			tarjan (i, v);
			low[u] = min (low[u], low[v]);
			if (low[v] >= dfn[u]) {
				++cnt;
				while (stk[tail + 1] != v)
				bcc[cnt].emplace_back (stk[tail--]);
				bcc[cnt].emplace_back (u);
			}
		}
		else if (i != (last ^ 1)) {
			low[u] = min (low[u], dfn[v]);
		}
	}
	if (last == -1 && !child) bcc[++cnt].emplace_back (u);
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
		if (!dfn[i]) tarjan (-1, i);
	}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; ++i) {
		int siz = bcc[i].size ();
		cout << siz << " ";
		for (int j = 0; j < siz; ++j) {
			cout << bcc[i][j] << " \n"[j == siz - 1];
		}
	}
}

signed main () {
	charming ();
	return 0;
}

*/