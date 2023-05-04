#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 20;

struct VirtualTree {
	int n, tot;
	vector <int> dfn, bot, siz, dep, isKey, bel, mn, id;
	vector <array <int, M> > fa;
	vector <vector <int> > G, nG;

	void Get (int f, int u, int d) {
		dfn[u] = ++tot, siz[u] = 1, fa[u][0] = f, dep[u] = d + 1;
		for (int i = 1; i < M; ++i) {
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
		}
		for (auto &v : G[u]) {
			if (v == f) continue;
			Get (u, v, d + 1);
			siz[u] += siz[v];
		}
		bot[u] = tot;
	}
	
	VirtualTree (int n, vector <vector <int> > &G) {
		this -> n = n, tot = 0;
		dfn = bot = siz = dep = isKey = bel = mn = id = vector <int> (n + 5);
		fa = vector <array <int, M> > (n + 5);
		this -> G = G, nG = vector <vector <int> > (n + 5);
		Get (0, 1, 1);
	}
	
	int Get_Lca (int u, int v) {
		if (dep[u] < dep[v]) swap (u, v);
		for (int i = M - 1; i >= 0; --i) {
			if (dep[fa[u][i]] > dep[v]) u = fa[u][i];
		}
		if (dep[u] > dep[v]) u = fa[u][0];
		for (int i = M - 1; i >= 0; --i) {
			if (fa[u][i] != fa[v][i]) {
				u = fa[u][i];
				v = fa[v][i];
			}
		}
		return u == v ? u : fa[u][0];
	}
	
	void Build (vector <int> &h) {
		sort (h.begin (), h.end (), [&] (int &x, int &y) {return dfn[x] < dfn[y];});
		for (int i = 0, siz = h.size (); i < siz - 1; ++i) {
			h.emplace_back (Get_Lca (h[i], h[i + 1]));
		}
		sort (h.begin (), h.end (), [&] (int &x, int &y) {return dfn[x] < dfn[y];});
		h.resize (unique (h.begin (), h.end ()) - h.begin ());
		vector <int> stk;
		stk.emplace_back (h[0]);
		for (int i = 1, siz = h.size (); i < siz; ++i) {
			while (bot[stk.back ()] < dfn[h[i]]) stk.pop_back ();
			nG[stk.back ()].emplace_back (h[i]);
			stk.emplace_back (h[i]);
		}
	}
	
	int Get_Dis (int u, int v) {return abs (dep[u] - dep[v]);}
	
	void DFS1 (int f, int u) {
		int dis;
		mn[u] = INT_MAX;
		for (auto &v : nG[u]) {
			DFS1 (u, v), dis = Get_Dis (u, v);
			if ((mn[v] + dis < mn[u]) || (mn[v] + dis == mn[u] 
			&& bel[v] < bel[u])) mn[u] = mn[v] + dis, bel[u] = bel[v];
		}
		if (isKey[u]) mn[u] = 0, bel[u] = u;
	}
	
	void DFS2 (int f, int u, vector <int> &ans) {
		int dis, extra = siz[u] - 1;
		for (auto &v : nG[u]) {
			dis = Get_Dis (u, v);
			if (mn[u] + dis < mn[v] || (mn[u] + dis == mn[v]
			&& bel[u] < bel[v])) mn[v] = mn[u] + dis, bel[v] = bel[u];
			DFS2 (u, v, ans);
		}
		ans[id[bel[u]]] += 1;
		for (auto &v : nG[u]) {
			int cut = v, f = v;
			for (int i = M - 1, dis1, dis2; i >= 0; --i) {
				if (dep[fa[cut][i]] > dep[u]) {
					dis1 = Get_Dis (fa[cut][i], bel[v]);
					dis2 = Get_Dis (u, fa[cut][i]) + mn[u];
					if (dis1 < dis2 || (dis1 == dis2 && bel[v] < bel[u])) {
						cut = fa[cut][i];
					}
				}
				if (dep[fa[f][i]] > dep[u]) f = fa[f][i];
			}
			extra -= siz[f];
			if (bel[v] == bel[u]) ans[id[bel[u]]] += siz[f] - siz[v];
			else {
				ans[id[bel[v]]] += siz[cut] - siz[v];
				ans[id[bel[u]]] += siz[f] - siz[cut];
			}
		}
		ans[id[bel[u]]] += extra;
	}
	
	vector <int> Solve (vector <pair <int, int> > &h) {
		vector <int> nh;
		for (auto &[v, i] : h) {
			isKey[v] = 1, id[v] = i;
			nh.emplace_back (v);
		}
		nh.emplace_back (1);
		vector <int> ans ((int) nh.size ());
		Build (nh), DFS1 (0, 1), DFS2 (0, 1, ans);
		for (auto &v : nh) {
			isKey[v] = bel[v] = id[v] = mn[v] = 0;
			nG[v].clear ();
		}
		return ans;
	}
};
	
int n, q;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <vector <int> > G (n + 5);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].emplace_back (v);
		G[v].emplace_back (u);
	}
	VirtualTree VT (n, G);
	cin >> q;
	for (int i = 1, k; i <= q; ++i) {
		cin >> k;
		vector <pair <int, int> > h (k);
		for (int j = 0; j < k; ++j) {
			cin >> h[j].first;
			h[j].second = j;
		}
		vector <int> ans = VT.Solve (h);
		for (int j = 0; j < k; ++j) {
			cout << ans[j] << " \n"[j == k - 1];
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
