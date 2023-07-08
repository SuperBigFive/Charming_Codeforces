#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct Tarjan {
	int n, tot, scc_cnt;
	vector <int> dfn, low, bel;
	vector <int> vis, isLeaf;
	vector <vector <int> > G, nG;
	
	Tarjan (int n, vector <vector <int> > &G) {
		this -> n = n, this -> tot = this -> scc_cnt = 0;
		this -> dfn = this -> low = this -> bel = vector <int> (n, -1);
		this -> vis = this -> isLeaf = vector <int> (n);
		this -> G = G, this -> nG = vector <vector <int> > (n);
	}
	
	void tarjan (int u, vector <int> &stk) {
		dfn[u] = low[u] = ++tot;
		stk.emplace_back (u);
		for (int v : G[u]) {
			if (dfn[v] <= -1) {
				tarjan (v, stk);
				low[u] = min (low[v], low[u]);
			}
			else if (bel[v] <= -1) low[u] = min (low[u], dfn[v]);
		}
		if (low[u] >= dfn[u]) {
			int v;
			do {
				v = stk.back ();
				stk.pop_back ();
				bel[v] = scc_cnt;
			} while (v != u);
			++scc_cnt;
		}
	}
	
	void Shrink () {
		for (int u = 0; u < n; ++u) {
			for (int v : G[u]) {
				if (bel[u] != bel[v]) {
					nG[bel[u]].emplace_back (bel[v]);
				}
			}
		}
	}
	
	void DFS (int u) {
		vis[u] = true;
		for (int v : nG[u]) {
			if (!vis[v]) DFS (v);
			isLeaf[u] |= isLeaf[v];
		}
	}
};

int n, m, s, haveCircle;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <int> > G (n);
	for (int u = 0, c; u < n; ++u) {
		cin >> c;
		for (int i = 0, v; i < c; ++i) {
			cin >> v, --v;
			G[u].emplace_back (v);
			if (u == v) haveCircle = true;
		}
	}
	cin >> s;
	Tarjan T (n, G);
	vector <int> stk;
	for (int i = 0; i < n; ++i) {
		if (T.dfn[i] <= -1) {
			stk.clear ();
			T.tarjan (i, stk);
		}
	}
	T.Shrink ();
	for (int i = 0; i < n; ++i) {
		if ((int) G[i].size () == 0) 
		T.isLeaf[T.bel[i]] = true;
	}
	for (int i = 0; i < T.scc_cnt; ++i) {
		if (!T.vis[i]) T.DFS (i);
	}
	vector <int> vis1 (n), vis2 (n), flag (n), dep (n), fa (n, -1);
	for (int i = 0; i < n; ++i) flag[i] = T.isLeaf[T.bel[i]];
	
	auto DFS = [&] (auto && me, int u, vector <int> &stk, vector <int> &vis) -> bool {
		stk.emplace_back (u);
		vis[u] = true;
		if (!G[u].size ()) return true;
		for (int v : G[u]) {
			if (vis[v]) continue;
			else if (me (me, v, stk, vis)) return true;
		}
		stk.pop_back ();
		return false;
	};
	
	vector <int> q;
	int head = 0, tail = 0, u;
	q.emplace_back (s - 1), tail += 1, vis1[s - 1] = 1;
	while (head < tail) {
		u = q[head++];
		if ((int) G[u].size () == 0 && (dep[u] & 1)) {
			vector <int> stk;
			while (u > -1) stk.emplace_back (u), u = fa[u];
			cout << "Win" << endl;
			while (!stk.empty ()) {
				cout << stk.back () + 1 << " \n"[(int) stk.size () == 1];
				stk.pop_back ();
			}
			return;
		}
		for (int v : G[u]) {
			if (!vis1[v]) {
				vis1[v] = true;
				fa[v] = u;
				q.emplace_back (v), ++tail;
				dep[v] = dep[u] ^ 1;
			}
			else if (dep[u] == dep[v] && flag[v]) {
				vector <int> stk0, stk1;
				DFS (DFS, v, stk1, vis2);
				if (((int) stk1.size () + dep[v]) & 1) {
					while (u > -1) stk0.emplace_back (u), u = fa[u];
				}
				else {
					v = fa[v];
					while (v > -1) stk0.emplace_back (v), v = fa[v];
				}
				cout << "Win" << endl;
				while (!stk0.empty ()) {
					cout << stk0.back () + 1<< " ";
					stk0.pop_back ();
				}
				for (int i = 0, siz = stk1.size (); i < siz; ++i) {
					cout << stk1[i] + 1 << " \n"[i == siz - 1];
				}
				return;
			}
		}
	}
	vector <int> cnt (T.scc_cnt);
	for (int i = 0; i < n; ++i) if (vis1[i]) {
		++cnt[T.bel[i]];
		if (cnt[T.bel[i]] > 1) haveCircle = true;
	}
	if (haveCircle) cout << "Draw" << endl;
	else cout << "Lose" << endl;
}

signed main () {
	charming ();
	return 0;
}