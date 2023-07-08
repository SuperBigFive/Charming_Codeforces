#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct RoundSquareTree {
	int n, tot, bcc_cnt;
	vector <int> dfn, low, siz;
	vector <vector <int> > G, nG;
	
	RoundSquareTree (int n, vector <vector <int> > &G) {
		this -> n = n, tot = bcc_cnt = 0;
		dfn = low = vector <int> (n << 2), siz = vector <int> (n << 2, -1);
		this -> G = G, nG = vector <vector <int> > (n << 2);
	}
	
	void Tarjan (int f, int u, vector <int> &stk) {
		dfn[u] = low[u] = ++tot;
		stk.emplace_back (u);
		for (auto &v : G[u]) {
			if (v == f) continue;
			else if (!dfn[v]) {
				Tarjan (u, v, stk);
				low[u] = min (low[u], low[v]);
				if (low[v] >= dfn[u]) {
					++bcc_cnt;
					siz[bcc_cnt + n] = 0;
					int nv;
					do {
						nv = stk.back ();
						++siz[bcc_cnt + n];
						nG[bcc_cnt + n].emplace_back (nv);
						nG[nv].emplace_back (bcc_cnt + n);
						stk.pop_back ();
					} while (nv != v);
					++siz[bcc_cnt + n];
					nG[bcc_cnt + n].emplace_back (u);
					nG[u].emplace_back (bcc_cnt + n);
				}
			} else low[u] = min (low[u], dfn[v]);
		}
	}
	
	void Build () {
		vector <int> stk;
		for (int i = 1; i <= n; ++i) if (!dfn[i]) {
			stk.clear (), Tarjan (0, i, stk);
		}
	}
};

int n, m;

void init () {}

int Get_Sum (int f, int u, vector <vector <int> > &G) {
	int ans = (u <= n);
	for (auto &v : G[u]) {
		if (v == f) continue;
		ans += Get_Sum (u, v, G);
	}
	return ans;
}

int DFS_DP (int f, int u, int sum, int &ans, vector <int> &vis, 
vector <int> &val, vector <vector <int> > &G) {
	int round_cnt = (val[u] < 0), tmp;
	vis[u] = 1;
	for (auto &v : G[u]) {
		if (v == f) continue;
		tmp = DFS_DP (u, v, sum, ans, vis, val, G);
		ans += val[u] * round_cnt * tmp;
		round_cnt += tmp;
	}
	ans += val[u] * (sum - round_cnt) * round_cnt;
	return round_cnt;
}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <int> > G (n << 2);
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		G[u].emplace_back (v);
		G[v].emplace_back (u);
	}
	RoundSquareTree RST (n, G);
	RST.Build ();
	int ans = 0;
	vector <int> vis (n << 2);
	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		DFS_DP (0, i, Get_Sum (0, i, RST.nG), ans, vis, RST.siz, RST.nG);
	}
	cout << ans * 2 << endl;
}

signed main () {
	charming ();
	return 0;
}