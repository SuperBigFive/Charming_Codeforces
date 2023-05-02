#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e3 + 5;

struct Blossom_Algorithm {
	int n, dfn;
	vector <int> label, match, pre, vis, fa;
	vector <vector <int> > G;	
	
	Blossom_Algorithm (int n, vector <vector <int> > &G) {
		this -> n = n, dfn = 0;
		label = match = pre = vis = fa = vector <int> (n + 5);
		this -> G = G;
	}
	
	int find (int x) {
		if (x == pre[x]) return x;
		return pre[x] = find (pre[x]);
	}
	
	int Get_Lca (int u, int v) {
		++dfn;
		while (true) {
			if (u) {
				u = find (u);
				if (vis[u] == dfn) break;
				else vis[u] = dfn, u = fa[match[u]];
			}
			swap (u, v); 
		}
		return u;
	}
	
	void Blossom (int u, int v, int rt, vector <int> &q) {
		while (find (u) != rt) {
			fa[u] = v, v = match[u];
			if (find (u) == u) pre[u] = rt;
			if (find (v) == v) pre[v] = rt;
			if (label[v] == 1) label[v] = 0, q.emplace_back (v);
			u = fa[v]; 
		}
	}
	
	bool Augment (int s) {
		label = vector <int> (n + 5, -1), fa = vector <int> (n + 5);
		iota (pre.begin (), pre.end (), 0);
		int head = 0;
		vector <int> q;
		q.emplace_back (s), label[s] = 0;
		while (head < q.size ()) {
			int u = q[head++];
			for (auto &v : G[u]) {
				if (label[v] == 1 || find (u) == find (v)) continue;
				else if (label[v] == -1) {
					label[v] = 1, fa[v] = u;
					if (!match[v]) {
						for (int x = v, last; x; x = last) {
							last = match[fa[x]], match[x] = fa[x], match[fa[x]] = x;
						}
						return true;
					}
					label[match[v]] = 0, q.emplace_back (match[v]);
				}
				else {
					int LCA = Get_Lca (u, v);
					Blossom (u, v, LCA, q), Blossom (v, u, LCA, q);
				}
			}
		}
		return false;
	}
	
	int GetMaxMatch () {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (match[i]) continue;
			else ans += Augment (i);
		}
		return ans;
	}
};

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <int> > G (n + 5);
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		G[u].emplace_back (v);
		G[v].emplace_back (u);
	}
	cout << Blossom_Algorithm (n, G).GetMaxMatch () << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}

//https://osilly.space/index.php/archives/9/