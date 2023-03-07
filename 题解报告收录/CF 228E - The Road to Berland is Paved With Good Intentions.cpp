#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, m, tot, cnt, scc_cnt, tail;
int dfn[maxn], low[maxn];
int bel[maxn], stk[maxn];
int to[maxn], nxt[maxn], head[maxn];
vector <int> scc[maxn], adj[maxn];

void add (int u, int v) {
	to[cnt] = v, nxt[cnt] = head[u], head[u] = cnt++;
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
	if (low[u] >= dfn[u]) {
		++scc_cnt;
		while (true) {
			scc[scc_cnt].emplace_back (stk[tail]);
			bel[stk[tail]] = scc_cnt;
			if (stk[tail--] == u) break;
		}
	}
}

void init () {
	fill (head, head + maxn, -1);
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		if (w) {
			add (u, v);
			add (v, u);
			add (u + n, v + n);
			add (v + n, u + n);
		}
		else {
			add (u, v + n);
			add (v, u + n);
			add (u + n, v);
			add (v + n, u);
		}
	}
	for (int i = 1; i <= (n << 1); ++i) if (!dfn[i]) {
		tarjan (i);
	}
	vector <int> res;
	for (int i = 1; i <= n; ++i) {
		if (bel[i] < bel[i + n]) res.emplace_back (i);
		if (bel[i] == bel[i + n]) {
			cout << "Impossible" << endl;
			return;
		}
	}
	cout << res.size () << endl;
	for (auto it : res) cout << it << " \n"[it == res.back ()];
}

signed main () {
	charming ();
	return 0;	
}