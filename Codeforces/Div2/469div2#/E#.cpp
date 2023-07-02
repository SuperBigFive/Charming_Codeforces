#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct Tarjan {
	int n, tot, scc_cnt;
	vector <int> dfn, low, bel;
	vector <int> stk, chu, siz;
	vector <vector <int> > G;
	
	Tarjan (int n, vector <vector <int> > &G) {
		this -> n = n, this -> tot = this -> scc_cnt = 0;
		this -> dfn = this -> low = this -> bel = vector <int> (n + 5, -1);
		this -> chu = this -> siz = vector <int> (n + 5);
		this -> G = G;
	}
	
	void tarjan (int u) {
		dfn[u] = low[u] = ++tot;
		stk.emplace_back (u);
		for (int v : G[u]) {
			if (dfn[v] == -1) {
				tarjan (v);
				low[u] = min (low[u], low[v]);
			}
			else if (bel[v] == -1) low[u] = min (low[u], dfn[v]);
		}
		if (low[u] >= dfn[u]) {
			++scc_cnt;
			int tmp;
			do {
				tmp = stk.back ();
				bel[tmp] = scc_cnt;
				++siz[scc_cnt];
				stk.pop_back ();
			} while (tmp != u);
		}
	}
	
	void Shrink () {
		for (int u = 1; u <= n; ++u) {
			for (int v : G[u]) {
				if (bel[u] != bel[v]) {
					++chu[bel[u]];
				}
			}
		}
	}
};

int n, m, h;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> h;
	vector <int> a (n + 5);
	vector <vector <int> > G (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int j = 1, c1, c2; j <= m; ++j) {
		cin >> c1 >> c2;
		if ((a[c1] + 1) % h == a[c2]) {
			G[c1].emplace_back (c2);
		}
		if ((a[c2] + 1) % h == a[c1]) {
			G[c2].emplace_back (c1);
		}
	}
	Tarjan T (n, G);
	for (int i = 1; i <= n; ++i) {
		if (T.bel[i] == -1) T.tarjan (i);
	}
	T.Shrink ();
	int k = INT_MAX, id;
	vector <int> ans;
	for (int i = 1; i <= T.scc_cnt; ++i) {
		if (!T.chu[i] && T.siz[i] < k) {
			k = T.siz[i];
			id = i;
		}
	}
	for (int i = 1; i <= n; ++i) if (T.bel[i] == id) ans.emplace_back (i);
	cout << k << endl;
	for (int i : ans) cout << i << " \n"[i == ans.back ()];
}

signed main () {
	charming ();
	return 0;
}