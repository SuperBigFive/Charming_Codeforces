#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 20;

struct VirtualTree {
	int n, tot;
	vector <int> dfn, bot, dep, isKey, cut;
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
		dfn = bot = dep = isKey = cut = vector <int> (n + 5);
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
		vector <int> stk (1, h[0]);
		for (int i = 1, siz = h.size (); i < siz; ++i) {
			while (bot[stk.back ()] < dfn[h[i]]) stk.pop_back ();
			nG[stk.back ()].emplace_back (h[i]);
			stk.emplace_back (h[i]);
		}
	}
	
	int DFS (int u) {
		int ans = 0, nxt, cnt = 0;
		for (auto &v : nG[u]) {
			nxt = DFS (v);
			if (nxt == -1 || (isKey[u] && isKey[v] 
			&& dep[u] == dep[v] - 1)) return -1;
			else if (isKey[u]) ans += (!cut[v]);
			ans += nxt, cnt += (!cut[v]);
		}
		if (!isKey[u] && cnt > 1) ++ans, cut[u] = 1;
		else if (!isKey[u] && cnt == 0) cut[u] = 1;
		return ans;
	}
	
	int Solve (vector <int> &h) {
		for (auto &v : h) isKey[v] = 1;
		Build (h);
		int ans = DFS (h[0]);
		for (auto &v : h) isKey[v] = cut[v] = 0, nG[v].clear ();
		return ans;
	}
};

int n, m;

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