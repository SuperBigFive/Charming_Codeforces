#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 20;

struct Node {
	int mx_suf, mx_seg;
	int mn_suf, mn_seg;
	
	void Merge (Node &a) {
		this -> mx_seg = max ({this -> mx_seg, a.mx_seg, this -> mx_suf - a.mn_suf});
		this -> mn_seg = min ({this -> mn_seg, a.mn_seg, this -> mn_suf - a.mx_suf});
		this -> mx_suf = max (this -> mx_suf, a.mx_suf);
		this -> mn_suf = min (this -> mn_suf, a.mn_suf);
	}
};

int Get_lca (int u, int v, vector <vector <int> > &fa, vector <int> &dep) {
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

Node Get_ans (int u, int lca, vector <vector <Node> > &node, 
vector <vector <int> > &fa, vector <int> &dep) {
	Node ans = {-1, -1, -1, -1};
	for (int i = M - 1; i >= 0; --i) {
		if (dep[fa[u][i]] >= dep[lca]) {
			if (ans.mx_seg == -1) ans = node[u][i];
			else ans.Merge (node[u][i]);
			u = fa[u][i];
		}
	}
	if (ans.mx_seg == -1) ans = node[u][0];
	else ans.Merge (node[u][0]);
	return ans;
}

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <vector <int> > fa (n + 5, vector <int> (M));
	vector <vector <Node> > node (n + 5, vector <Node> (M));
	node[1][0] = (Node) {1, 1, 1, 0};
	vector <int> suf (n + 5), dep (n + 5), val (n + 5);
	suf[1] = dep[1] = val[1] = 1;
	for (int i = 1; i < M; ++i) node[1][i] = node[1][i - 1];
	char op;
	for (int i = 1, u, v, x, k, cnt = 1, mn, mx, lca; i <= n; ++i) {
		cin >> op;
		if (op == '+') {
			++cnt, cin >> v >> x;
			fa[cnt][0] = v;
			for (int i = 1; i < M; ++i) fa[cnt][i] = fa[fa[cnt][i - 1]][i - 1];
			suf[cnt] = suf[v] + x, dep[cnt] = dep[v] + 1, val[cnt] = x;
			node[cnt][0] = (Node) {suf[cnt], max (0ll, x), suf[cnt], min (0ll, x)};
			for (int i = 1; i < M; ++i) {
				node[cnt][i] = node[cnt][i - 1];
				node[cnt][i].Merge (node[fa[cnt][i - 1]][i - 1]);
			}
		} else {
			cin >> u >> v >> k;
			mn = mx = 0;
			lca = Get_lca (u, v, fa, dep);
			Node ans_u = Get_ans (u, lca, node, fa, dep);
			Node ans_v = Get_ans (v, lca, node, fa, dep);
			mn = min ({mn, ans_u.mn_seg, ans_v.mn_seg, ans_u.mn_suf + ans_v.mn_suf - suf[lca] * 2 + val[lca]});
			mx = max ({mx, ans_u.mx_seg, ans_v.mx_seg, ans_u.mx_suf + ans_v.mx_suf - suf[lca] * 2 + val[lca]});
			if (k >= mn && k <= mx) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}