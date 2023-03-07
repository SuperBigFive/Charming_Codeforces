#include <bits/stdc++.h>
#define ll long long
#define int ll 
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;


int n, q, now_s;
int ans[maxn];
int cnt[maxn], siz[maxn], son[maxn], dep[maxn];
int fa[maxn][32];
vi adj[maxn];
vector <pii> query[maxn];

void init () {
	
}

void get_kf (int &u, int k) {
	for (int i = 31; i >= 0; --i) {
		if (k & (1 << i)) u = fa[u][i];
	}
}

void dfs (int f, int u, int d) {
	siz[u] = 1;
	dep[u] = d;
	fa[u][0] = f;
	for (int i = 1; i < 32; ++i) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs (u, it, d + 1);
		siz[u] += siz[it];
		if (siz[son[u]] < siz[it]) son[u] = it;
	}
}

void cal (int f, int u, int val) {
	cnt[dep[u]] += val;
	for (auto it : adj[u]) {
		if (it == f || it == now_s) continue;
		cal (u, it, val);
	}
}

void dsu (int f, int u, int st) {
	for (auto it : adj[u]) {
		if (it == f || it == son[u]) continue;
		dsu (u, it, 0);
	}
	if (son[u]) dsu (u, son[u], 1), now_s = son[u];
	cal (f, u, 1);
	if (!u) return;
	for (auto it : query[u]) {
		ans[it.fi] = cnt[dep[u] + it.se] - 1;
	}
	now_s = 0;
	if (!st) cal (f, u, -1);
}

void charming () {
	cin >> n;
	int f;
	for (int i = 1; i <= n; ++i) {
		cin >> f;
		adj[f].emplace_back (i);
	}
	dfs (-1, 0, 0);
	cin >> q;
	int v, k;
	for (int i = 1; i <= q; ++i) {
		cin >> v >> k;
		get_kf (v, k);
		query[v].emplace_back (make_pair (i, k));
	}
	dsu (-1, 0, 1);
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << (i == q ? "\n" : " ");
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}