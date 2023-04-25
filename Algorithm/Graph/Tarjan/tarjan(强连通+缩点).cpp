#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;

int n, m, tot, cnt, times, tail;
int val[maxn], bel[maxn], ans[maxn];
int dfn[maxn], low[maxn], stk[maxn];
int from[maxn], to[maxn], nxt[maxn], head[maxn];
vector <int> scc[maxn];

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
	stk[++tail] = u;
	for (int i = head[u], v; i != -1; i = nxt[i]) {
		v = to[i];
		if (!dfn[v]) {
			tarjan (i, v);
			low[u] = min (low[u], low[v]);
		}
		else if (!bel[v]) {
			low[u] = min (low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		++cnt;
		while (true) {
			val[cnt] += val[stk[tail]];
			bel[stk[tail]] = cnt;
			scc[cnt].emplace_back (stk[tail--]);
			if (scc[cnt].back () == u) break;
		}
	}
}

int dfs (int f, int u) {
	ans[u] = val[u];
	for (int i = head[u], v; i != -1; i = nxt[i]) {
		v = to[i];
		dfs (u, v);
		ans[u] = max (ans[u], val[u] + ans[v]);
	}
	return ans[u];
}

void charming () {
	init ();
	cin >> n >> m;
	cnt = n;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		if (u == v) continue;
		add_edge (u, v);
	}
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i]) tarjan (-1, i);
	}
	cout << cnt << endl;
	for (int u = 1; u <= n; ++u) {
		for (int i = head[u], v; i != -1; i = nxt[i]) {
			v = to[i];
			if (bel[u] != bel[v]) add_edge (bel[u], bel[v]);
		}
	}
	int res = 0;
	for (int i = n + 1; i <= cnt; ++i) {
		if (!ans[i]) res = max (res, dfs (-1, i));
	}
	cout << cnt << endl;
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}
