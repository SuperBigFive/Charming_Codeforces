#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, m;
vector <int> du (N), du2 (N), du4 (N), Sqrt (N), vis (N);
vector <int> stk;

void init () {
	for (int i = 0; i <= n; ++i)
	du[i] = du2[i] = du4[i] = vis[i] = 0;
}

void clear_tag (vector <int> &cdu2, vector <int> &cdu4) {
	for (auto &v : cdu2) du2[v] = 0;
	for (auto &v : cdu4) du4[v] = 0;
}

int dfs (int rt, int f, int u, vector <vector <int> > &G, vector <int> &DU) {
	stk.emplace_back (u);
	vis[u] = true;
	for (auto &v : G[u]) {
		if (v == f || (!DU[v] && v != rt)) continue;
		else if (vis[v] && v != rt) return -1;
		else if (v == rt) return stk.size ();
		else return dfs (rt, u, v, G, DU);
	}
	return -1;
}

bool is_K_Flower (vector <int> &V, vector <vector <int> > &G) {
	if (!Sqrt[(int) V.size ()] || (int) V.size () != n) return false;
	int p4 = -1, ok = 1, k = Sqrt[(int) V.size ()];
	vector <int> cdu2, cdu4;
	for (auto &v : V) {
		if (du[v] == 2) cdu2.emplace_back (v), du2[v] = 1;
		else if (du[v] == 4) cdu4.emplace_back (v), p4 = v, du4[v] = 1;
		else ok = false;
	}
	if (!ok || cdu4.size () != k) {
		clear_tag (cdu2, cdu4);
		return false;
	}
	stk.clear ();
	if (dfs (p4, 0, p4, G, du4) != k) {
		clear_tag (cdu2, cdu4);
		return false;
	}
	for (auto &v : cdu4) {
		stk.clear ();
		if (dfs (v, 0, v, G, du2) != k) {
			clear_tag (cdu2, cdu4);
			return false;
		}
	}
	return true;
}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> pre (n + 5);
	vector <vector <int> > adj (n + 5);
	
	auto find = [&] (auto && me, int x) -> int {
		if (x == pre[x]) return x;
		return pre[x] = me (me, pre[x]);
	};
	
	for (int i = 1; i <= n; ++i) pre[i] = i;
	for (int i = 1, u, v, fu, fv; i <= m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
		++du[u], ++du[v];
		fu = find (find, u), fv = find (find, v);
		if (fu == fv) continue;
		else pre[fu] = fv;
	}
	if (!Sqrt[n]) return void (cout << "NO" << endl);
	vector <vector <int> > same_pre (n + 5);
	for (int i = 1; i <= n; ++i) same_pre[find (find, i)].emplace_back (i);
	for (int i = 1; i <= n; ++i) {
		if (same_pre[i].size () && is_K_Flower (same_pre[i], adj)) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

signed main () {
	for (int i = 3; i * i < N; ++i) Sqrt[i * i] = i;
	cin >> t;
	while (t--) charming ();
	return 0;
}