#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m, tot, ok;
int bcc_cnt, cut_pcnt, cut_lcnt, mx_lcnt;
int dfn[N], low[N], bel[N], isCut[N], vis_l[N];
vector <int> stk_p, bcc[N];
vector <pair <int, int> > adj[N], stk_l;

void init () {}

void tarjan (int rt, int f, int u) {
	stk_p.emplace_back (u);
	dfn[u] = low[u] = ++tot;
	int child = 0;
	for (auto &[v, lid] : adj[u]) {
		lid >>= 1;
		if (v == f) continue;
		else if (!dfn[v]) {
			++child;
			if (!vis_l[lid]) {
				vis_l[lid] = 1;
				stk_l.emplace_back (make_pair (u, v));
			}
			tarjan (rt, u, v);
			if (low[v] >= dfn[u]) {
				isCut[u] = 1, ++bcc_cnt;
				int lcnt = 0;
				while (true) {
					++lcnt;
					auto [nu, nv] = stk_l.back ();
					stk_l.pop_back ();
					if (bel[nu] != bcc_cnt) {
						bcc[bcc_cnt].emplace_back (nu);
						bel[nu] = bcc_cnt;
					}
					if (bel[nv] != bcc_cnt) {
						bcc[bcc_cnt].emplace_back (nv);
						bel[nv] = bcc_cnt;
					}
					if (nu == u && nv == v) break;
				}
				mx_lcnt = max (mx_lcnt, lcnt);
			}
			if (low[v] > dfn[u]) ++cut_lcnt;
			low[u] = min (low[u], low[v]);
		}
		else {
			if (!vis_l[lid]) {
				vis_l[lid] = 1;
				stk_l.emplace_back (make_pair (u, v));
			}
			low[u] = min (low[u], dfn[v]);
		}
	}
	if (u == rt && child < 2) isCut[u] = 0;
}
	
void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (make_pair (v, (i - 1) * 2));
		adj[v].emplace_back (make_pair (u, i * 2 - 1));
	}
	for (int i = 1; i <= n; ++i) {	
		if (!bel[i]) tarjan (i, 0, i);
		cut_pcnt += isCut[i];
	}
	cout << cut_pcnt << " " << cut_lcnt << " " << bcc_cnt << " " << mx_lcnt << endl;
}

signed main () {
	charming ();
	return 0;
}