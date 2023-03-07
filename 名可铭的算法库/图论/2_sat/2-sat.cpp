#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, m, tot, scc_cnt, tail;
int dfn[maxn], low[maxn], bel[maxn], stk[maxn];
int to[maxn], nxt[maxn], head[maxn];
vector <int> scc[maxn];

void init () {fill (head, head + maxn, -1);}

void add_edge (int u, int v) {
	to[tot] = v;
	nxt[tot] = head[u];
	head[u] = tot++;	
}

void tarjan (int u) {
	dfn[u] = low[u] = ++tot;
	stk[++tail] = u;
	for (int i = head[u], v; i != -1; i = nxt[i]) {
		v = to[i];
		if (!dfn[v]) {
			tarjan (v);
			low[u] = min (low[u], low[v]);
		}
		else if (!bel[v]) {
			low[u] = min (low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		++scc_cnt;
		while (true) {
			bel[stk[tail]] = scc_cnt;
			scc[scc_cnt].emplace_back (stk[tail--]);
			if (scc[scc_cnt].back () == u) break;
		}
	}
}

void charming () {
	init ();
	cin >> n >> m;
	int sign[2] = {-1, 1};
	for (int k = 1, i, a, j, b; k <= m; ++k) {
		cin >> i >> a >> j >> b;
		if (!a) i += n;
		if (!b) j += n;
		add_edge (i + sign[a] * n, j);
		add_edge (j + sign[b] * n, i);
	}
	for (int i = 1; i <= (n << 1); ++i) {
		if (dfn[i]) continue;
		tarjan (i);
	}
	for (int i = 1; i <= n; ++i) {
		if (bel[i] == bel[i + n]) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
	cout << "POSSIBLE" << endl;
	for (int i = 1; i <= n; ++i) {
		cout << (bel[i] < bel[i + n]) << " \n"[i == n];
	}
}

signed main () {
	charming ();
	return 0;
}