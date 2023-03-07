#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e6 + 5;
const int mod = 1e9 + 7;

int t, n;
int f[N], siz[N], prim[N], ok[N];
vector <int> adj[N];

void init () {
	for (int i = 0; i <= n; ++i)
	f[i] = siz[i] = 0, adj[i].clear ();
}

void get_prim () {
	vector <int> vis (N);
	for (int i = 2, cnt = 0; i < N; ++i) {
		if (!vis[i]) prim[++cnt] = i;
		for (int j = 1; j <= cnt && i * prim[j] < N; ++j) {
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0) break;
		}
	}
}

void dfs (int fa, int u) {
	map <pair <int, int>, int> f_siz;
	map <pair <int, int>, int> id;
	f[u] = siz[u] = 1;
	for (auto &it : adj[u]) {
		if (it == fa) continue;
		dfs (u, it);
		siz[u] += siz[it];
		f_siz[make_pair (f[it], siz[it])] += 1;
		id[make_pair (f[it], siz[it])] = it;
		f[u] = (f[u] + f[it] * prim[siz[it]]) % mod;
	}
	bool flag = false;
	for (auto &[it, cnt] : f_siz) if (cnt & 1) {
		if (!flag) {ok[u] = ok[id[it]]; flag = true;}
		else {ok[u] = false; break;}
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	for (int i = 1; i <= n; ++i) ok[i] = 1;
	dfs (0, 1);
	cout << (ok[1] ? "YES" : "NO") << endl;
}

signed main () {
	get_prim ();
	cin >> t;
	while (t--) charming ();
	return 0;
}