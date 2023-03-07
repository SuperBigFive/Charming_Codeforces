#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, m, tot, cnt, times, tail;
int dfn[maxn], low[maxn];
int stk[maxn], bel[maxn], ans[maxn];
int to[maxn], nxt[maxn], head[maxn];
vector <int> scc[maxn];
map <int, int> nnxt[maxn];

void init () {
	fill (head, head + maxn, -1);
}

void add_edge (int u, int v) {
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
			scc[cnt].emplace_back (stk[tail]);
			bel[stk[tail]] = cnt;
			if (stk[tail--] == u) break;
		}
	}
}

void dfs (int u) {
	ans[u] = scc[u].size () - 1;
	for (int i = head[u], v; i != -1; i = nxt[i]) {
		v = to[i];
		dfs (v);
		ans[u] += ans[v] + 1;
	}
}

void charming () {
	init ();
	cin >> n >> m;
	cnt = n;
	int fi;
	for (int i = 1, last, cur; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> cur;
			if (j > 1) add_edge (last, cur);
			else fi = cur;
			last = cur;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!bel[i]) tarjan (-1, i);
	}
	for (int u = 1; u <= n; ++u) {
		for (int i = head[u], v; i != -1; i = nxt[i]) {
			v = to[i];
			if (bel[u] != bel[v] && !nnxt[bel[u]].count (bel[v]))
			add_edge (bel[u], bel[v]), ++nnxt[bel[u]][bel[v]];
		}
	}
	dfs (bel[fi]);
	for (int i = 1; i <= n; ++i) {
		cout << ans[bel[i]] << " \n"[i == n];
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}