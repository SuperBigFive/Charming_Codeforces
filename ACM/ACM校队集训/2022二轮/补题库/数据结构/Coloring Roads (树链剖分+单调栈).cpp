#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 4e5 + 5;

int n, m, c, q, tot;
int siz[maxn], h_son[maxn], fa[maxn], dep[maxn];
int dfn[maxn], rk[maxn], top[maxn], bottom[maxn];
int num[maxn], cnt[maxn];
vector <pii> stk[maxn];
vi adj[maxn];

int dfs1 (int f, int u, int d) {
	fa[u] = f;
	dep[u] = d;
	siz[u] = 1;
	for (auto it : adj[u]) {
		if (it == f) continue;
		siz[u] += dfs1 (u, it, d + 1);
		if (siz[it] > siz[h_son[u]]) h_son[u] = it;
	}
	return siz[u];
}

int dfs2 (int f, int u, int tp) {
	top[u] = tp;
	dfn[u] = ++tot;
	rk[tot] = u;
	bottom[u] = tot;
	if (h_son[u]) bottom[u] = max (bottom[u], dfs2 (u, h_son[u], tp));
	for (auto it : adj[u]) {
		if (it == f || it == h_son[u]) continue;
		bottom[u] = max (bottom[u], dfs2 (u, it, it));
	}
	return bottom[u];
}

void ChangeColor (int c, int value) {
	--num[cnt[c]];
	cnt[c] += value;
	++num[cnt[c]];
}

void Color (int u, int c) {
	pii now;
	int pre;
	while (u != 1) {
		pre = dfn[top[u]] - 1;
		if (top[u] == 1) ++pre;
		while (!stk[top[u]].empty () && stk[top[u]].back ().fi <= dfn[u]) {
			now = stk[top[u]].back ();
			ChangeColor (now.se, - (now.fi - pre));
			stk[top[u]].pop_back ();
			pre = now.fi;
		}
		if (!stk[top[u]].empty ()) {
			now = stk[top[u]].back ();
			ChangeColor (now.se, - (dfn[u] - pre));
		}
		stk[top[u]].pb ({dfn[u], c});
		ChangeColor (c, dfn[u] - dfn[top[u]] + 1);
		if (top[u] == 1) u = 1, ChangeColor (c, -1);
		else u = fa[top[u]];
	}
}

void charming () {
	cin >> n >> c >> q;
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[u].pb (v);
		adj[v].pb (u);
	}
	dfs1 (0, 1, 1);
	dfs2 (0, 1, 1);
	num[0] = c;
	for (int i = 1; i <= q; ++i) {
		cin >> u >> c >> m;
		Color (u, c);
		cout << num[m] << endl;
	}
}

signed main () {
	charming ();
	return 0;
}