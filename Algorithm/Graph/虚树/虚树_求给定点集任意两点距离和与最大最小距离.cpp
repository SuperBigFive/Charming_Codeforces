#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 20;

struct VirtualTree {
	int n, tot;
	vector <int> dfn, bot, dep, isKey;
	vector <array <int, 4> > dp;
	vector <array <int, M> > fa;
	vector <vector <int> > G, nG;
	
	void Get (int f, int u, int d) {
		dfn[u] = ++tot, dep[u] = d, fa[u][0] = f;
		for (int i = 1; i < M; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
		for (auto &v : G[u]) {
			if (v == f) continue;
			Get (u, v, d + 1);
		}
		bot[u] = tot;
	}
	
	VirtualTree (int n, vector <vector <int> > &G) {
		this -> n = n, tot = 0;
		dfn = bot = dep = isKey = vector <int> (n + 5);
		dp = vector <array <int, 4> > (n + 5);
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
		if (u != v) return fa[u][0];
		else return u;
	}
	
	void Build (vector <int> &h) {
		sort (h.begin (), h.end (), [&] (int x, int y) {return dfn[x] < dfn[y];});
		for (int i = 0, siz = h.size (); i < siz - 1; ++i) {
			h.emplace_back (Get_Lca (h[i], h[i + 1]));
		}
		sort (h.begin (), h.end (), [&] (int x, int y) {return dfn[x] < dfn[y];});
		h.resize (unique (h.begin (), h.end ()) - h.begin ());
		vector <int> stk;
		stk.emplace_back (h[0]);
		for (int i = 1; i < h.size (); ++i) {
			while (bot[stk.back ()] < dfn[h[i]]) stk.pop_back ();
			nG[stk.back ()].emplace_back (h[i]);
			stk.emplace_back (h[i]);
		}
	}
	
	int Get_Dis (int u, int v) {return abs (dep[u] - dep[v]);}
	
	array <int, 4> DFS (int u, int &sum, int &mx, int &mn) {
		array <int, 4> cur = {0, -1, INT_MAX, 0}, nxt;
		if (isKey[u]) cur[1] = cur[2] = 0, cur[3] = 1;
		for (auto &v : nG[u]) {
			nxt = DFS (v, sum, mx, mn);
			int dis = Get_Dis (v, u);
			sum += (nxt[0] + dis * nxt[3]) * cur[3] + nxt[3] * cur[0];
			mx = max (mx, cur[1] + nxt[1] + dis);
			mn = min (mn, cur[2] + nxt[2] + dis);
			cur[0] += (nxt[0] + dis * nxt[3]);
			cur[1] = max (cur[1], nxt[1] + dis);
			cur[2] = min (cur[2], nxt[2] + dis);
			cur[3] += nxt[3];
		}
		return cur;
	}
	
	array <int, 3> Solve (vector <int> &h) {
		for (auto &v : h) isKey[v] = 1;
		Build (h);
		array <int, 3> ans = {0, -1, INT_MAX};
		DFS (h[0], ans[0], ans[1], ans[2]);
		for (auto &v : h) isKey[v] = 0, nG[v].clear ();
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
		vector <int> h (k);
		while (k--) cin >> h[k];
		array <int, 3> ans = VT.Solve (h);
		swap (ans[1], ans[2]);
		cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}