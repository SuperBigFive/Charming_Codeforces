#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fi first
#define se second
#define inl inline
#define rg register int
using namespace std;
const int maxn = 2e5 + 5;

int n, m, rt;
int l[maxn], r[maxn], val[maxn], res[maxn];
bool vis[maxn];
vi adj[maxn]; 

void init () {
	for (int i = 1; i < maxn; ++i) l[i] = -INT_MAX, r[i] = INT_MAX;
}

bool dfs1 (int f, int u, int st) {
	if (vis[u] && ((val[u] & 1) != st)) return false;
	for (auto it : adj[u]) {
		if (it == f) continue;
		if (!dfs1 (u, it, (st ^ 1))) return false;;
	}
	return true;
}

bool dfs2 (int f, int u) {
	if (vis[u]) l[u] = r[u] = val[u];
	for (auto it : adj[u]) {
		if (it == f) continue;
		if (!dfs2 (u, it)) return false;
		l[u] = max (l[u], l[it] - 1);
		r[u] = min (r[u], r[it] + 1);
	}
	return l[u] <= r[u];
}

void dfs3 (int f, int u, int w) {
	res[u] = w;
	for (auto it : adj[u]) {
		if (it == f) continue;
		if (l[it] <= w - 1 && w - 1 <= r[it]) dfs3 (u, it, w - 1);
		else dfs3 (u, it, w + 1);
	}
}

void charming () {
	init ();
	cin >> n;
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[u].pb (v);
		adj[v].pb (u);
	}
	cin >> m;
	int p, c;
	for (int i = 1; i <= m; ++i) {
		cin >> p >> c;
		val[p] = c;
		vis[p] = true;
		rt = p;
	}
	if (!dfs1 (0, rt, val[rt] & 1) || !dfs2 (0, rt)) {
		cout << "No" << endl;
		return;
	}
	dfs3 (0, rt, val[rt]);
	cout << "Yes" << endl;
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}