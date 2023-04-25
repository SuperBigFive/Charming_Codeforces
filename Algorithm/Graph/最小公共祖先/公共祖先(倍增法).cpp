#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 5e5 + 5;

int n, q, root;
int depth[maxn];
int fa[maxn][32], d[maxn][32];
vi adj[maxn], w[maxn];

void init () {
	
}

void dfs (int f, int u, int dep) {
	fa[u][0] = f;
	depth[u] = dep;
	for (int i = 1; i <= 31; ++i) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
		d[u][i] = d[fa[u][i - 1]][i - 1] + d[u][i - 1];
	}
	int v;
	for (int i = 0; i < adj[u].size (); ++i) {
		v = adj[u][i];
		if (v == f) continue;
		d[v][0] = w[u][i];
		dfs (u, v, dep + 1);
	}
}

int lca (int a, int b) {
	int res = 0;
	if (depth[a] < depth[b]) swap (a, b);
	int diff = depth[a] - depth[b];
	for (int i = 0; i <= 31 && diff; ++i) {
		if (diff & 1) {
			res += d[a][i];
			a = fa[a][i];
		}
		diff >>= 1;
	}
	if (a == b) return a;
	for (int j = 31; j >= 0 && a != b; --j) {
		if (fa[a][j] != fa[b][j]) {
			res += d[a][j] + d[b][j];
			a = fa[a][j];
			b = fa[b][j];
		}
	}
	res += d[a][0] + d[b][0];
	return fa[a][0];
}

void charming () {
	cin >> n >> q;
	int u, v, c;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[u].pb (v);
		adj[v].pb (u);
		w[u].pb (1);
		w[v].pb (1);
	}
	dfs (0, 1, 1);
	int a, b;
	ll ans, k, Lca;
	for (int i = 1; i <= q; ++i) {
		cin >> a >> b;
		if (a == b) {
			cout << n << endl;
			continue;
		}
		Lca = lca (a, b);
		k = depth[a] + depth[b] - 2 * depth[Lca] + 1;
		ans = n + (k - 1) + (k - 2) * (k - 3) / 2 + k - 2;
		cout << ans << endl;
	}
}

signed main () {
	charming ();
	return 0;
}