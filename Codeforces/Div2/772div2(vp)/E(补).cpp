#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, m, tot, scc_cnt, tail;
int pos[maxn], st[maxn], in[maxn];
vector <int> adj[maxn];

namespace Two_sat {
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
}

bool topu () {
	for (int i = 1; i <= n; ++i) 
	for (auto it : adj[i]) ++in[it];
	queue <int> q;
	for (int i = 1; i <= n; ++i) if (!in[i]) {
		q.push (i);
	}
	int cur, cnt = 0;
	while (!q.empty ()) {
		cur = q.front ();
		q.pop ();
		pos[cur] = ++cnt;
		for (auto it : adj[cur]) {
			--in[it];
			if (in[it] <= 0) q.push (it);
		}
	}
	return cnt == n;
}

void charming () {
	Two_sat :: init ();
	cin >> n >> m;
	vector <array <int, 3> > cons (m + 1, {0, 0, 0});
	for (int k = 1, type, i, j; k <= m; ++k) {
		cin >> type >> i >> j;
		cons[k][0] = type, cons[k][1] = i, cons[k][2] = j;
		Two_sat :: add_edge (i, j + n);
		Two_sat :: add_edge (i + n, j);
		Two_sat :: add_edge (j, i + n);
		Two_sat :: add_edge (j + n, i);
	}
	for (int i = 1; i <= (n << 1); ++i) {
		if (Two_sat :: dfn[i]) continue;
		Two_sat :: tarjan (i);
	}
	for (int i = 1; i <= n; ++i) {
		if (Two_sat :: bel[i] == Two_sat :: bel[i + n]) {
			cout << "NO" << endl;
			return;
		}
	}
	for (int i = 1; i <= n; ++i) {
		st[i] = (Two_sat :: bel[i] < Two_sat :: bel[i + n]);
	}
	for (auto [type, i, j] : cons) {
		if (type == 0) continue;
		else if (st[i] == st[j]) {
			cout << "NO" << endl;
			return;
		}
		else if ((type - 1) ^ st[i]) {
			adj[j].emplace_back (i);
		}
		else adj[i].emplace_back (j);
	}
	if (!topu ()) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i) {
		cout << (st[i] ? "R " : "L ") << pos[i] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}