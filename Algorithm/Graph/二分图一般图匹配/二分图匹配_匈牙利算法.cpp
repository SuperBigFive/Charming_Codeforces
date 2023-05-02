#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n0, n1, m;

struct Augment_path {
	int n0, n1, m, ans, dfn;
	vector <int> pa, pb, vis;
	vector <vector <int> > G;
	
	Augment_path (int n0, int n1, int m, vector <vector <int> > G) {
		this -> n0 = n0, this -> n1 = n1, this -> m = m;
		this -> G = G;
		pa = vector <int> (n0 + 5, -1);
		pb = vector <int> (n1 + 5, -1);
		vis.resize (n0 + 5);
		ans = dfn = 0;
	}
	
	bool Augment (int u) {
		vis[u] = dfn;
		for (auto &v : G[u]) if (pb[v] == -1) {
			pa[u] = v;
			pb[v] = u;
			return true;
		}
		for (auto &v : G[u]) {
			if (vis[pb[v]] != dfn && Augment (pb[v])) {
				pa[u] = v;
				pb[v] = u;
				return true;
			}
		}
		return false;
	}
	
	int MaxMatch () {
		while (true) {
			++dfn;
			int cnt = 0;
			for (int i = 1; i <= n0; ++i) {
				if (pa[i] == -1 && Augment (i)) ++cnt, ++ans;
			}
			if (cnt == 0) break;
		}
		return ans;
	}
};

void init () {}

void charming () {
	init ();
	cin >> n0 >> n1 >> m;
	vector <vector <int> > G (n0 + 5);
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		G[u].emplace_back (v);
	}
	cout << Augment_path (n0, n1, m, G).MaxMatch () << endl;
}

signed main () {
	charming ();
	return 0;
}