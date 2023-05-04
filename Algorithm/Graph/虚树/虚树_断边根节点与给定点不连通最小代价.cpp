#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e5 + 5;
const int M = 20;

struct VirturalTree {
	int n, tot;
	vector <int> dfn, bot, dep, dp, isKey;
	vector <array <int, M> > fa, mnDis;
	vector <vector <pair <int, int> > > G, nG;
	
	void Get (int f, int u, int lw, int d) {
		dfn[u] = ++tot, dep[u] = d;
		fa[u][0] = f, mnDis[u][0] = lw;
		for (int i = 1; i < M; ++i) {
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
			mnDis[u][i] = min (mnDis[u][i - 1], mnDis[fa[u][i - 1]][i - 1]);
		}
		for (auto &[v, w] : G[u]) {
			if (v == f) continue;
			Get (u, v, w, d + 1);
		}
		bot[u] = tot;
	}
	
	VirturalTree (int n, vector <vector <pair <int, int> > > &G) {
		this -> n = n, tot = 0;
		dfn = bot = dep = dp = isKey = vector <int> (n + 5);
		fa = mnDis = vector <array <int, M> > (n + 5);
		for (auto &it1 : mnDis) for (auto &it2 : it1) it2 = INT_MAX;
		this -> G = G, nG = vector <vector <pair <int, int> > > (n + 5);
		Get (0, 1, 0, 1);
	}
	
	int Get_Lca (int u, int v) {
		if (dep[u] < dep[v]) swap (u, v);
		for (int i = M - 1; i >= 0; --i) {
			if (dep[fa[u][i]] > dep[v]) u = fa[u][i];
		}
		if (dep[u] > dep[v]) u = fa[u][0];
		for (int i = M - 1; i >= 0; --i) {
			if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
		}
		if (u != v) return fa[u][0];
		else return u;
	}
	
	int Get_mnDis (int u, int v) {
		int ans = INT_MAX;
		for (int i = M - 1; i >= 0; --i) {
			if (dep[fa[u][i]] > dep[v]) {
				ans = min (ans, mnDis[u][i]);
				u = fa[u][i];
			}
		}
		if (dep[u] > dep[v]) return min (ans, mnDis[u][0]);
		else return ans;
	}
	
	void Build (vector <int> &h) {
		sort (h.begin (), h.end (), [&] (int x, int y) {return dfn[x] < dfn[y];});
		h.resize (unique (h.begin (), h.end ()) - h.begin ());
		for (int i = 0, siz = h.size (); i < siz - 1; ++i) {
			h.emplace_back (Get_Lca (h[i], h[i + 1]));
		}
		sort (h.begin (), h.end (), [&] (int x, int y) {return dfn[x] < dfn[y];});
		h.resize (unique (h.begin (), h.end ()) - h.begin ());
		vector <int> stk (1, 1);
		for (int i = 1; i < h.size (); ++i) {
			while (bot[stk.back ()] < dfn[h[i]]) stk.pop_back ();
			nG[stk.back ()].emplace_back (make_pair (h[i], Get_mnDis (h[i], stk.back ())));
			stk.emplace_back (h[i]);
		}
	}
	
	void DFS (int u) {
		for (auto &[v, w] : nG[u]) {
			DFS (v);
			if (isKey[v]) dp[u] += w;
			else dp[u] += min (dp[v], w);
		}
	}
	
	ll Solve (vector <int> &h) {
		for (auto &v : h) isKey[v] = 1;
		h.emplace_back (1);
		Build (h), DFS (1);
		ll ans = dp[1];
		for (auto &v : h) dp[v] = isKey[v] = 0, nG[v].clear ();
		return ans;
	}
};

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <vector <pair <int, int> > > G (n + 5);
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		G[u].emplace_back (make_pair (v, w));
		G[v].emplace_back (make_pair (u, w));
	}
	VirturalTree VT (n, G);
	cin >> m;
	for (int i = 1, k; i <= m; ++i) {
		cin >> k;
		vector <int> h (k);
		while (k--) cin >> h[k];
		cout << VT.Solve (h) << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}