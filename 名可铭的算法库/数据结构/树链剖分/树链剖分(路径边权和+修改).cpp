#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int n, m, root, mod;
int val[maxn], fa[maxn], dep[maxn], h_son[maxn], siz[maxn];
int top[maxn], dfn[maxn], rk[maxn], bottom[maxn];
vi adj[maxn];

struct Node {
	int l;
	int r;
	int sum;
	int lazy_add;
}node[maxn << 1];
int tot;
int tl[maxn << 1], tr[maxn << 1];

void updata (int cnt) {
	node[cnt].sum = node[tl[cnt]].sum + node[tr[cnt]].sum;
}

void build (int cnt, int l, int r) {
	node[cnt].l = l, node[cnt].r = r;
	if (l == r) {
		if (l != 1) node[cnt].sum = max (abs (val[rk[l]] - val[fa[rk[l]]]), abs (val[rk[l]] + val[fa[rk[l]]]));
		return;
	}
	int mid = (l + r) / 2;
	if (!tl[cnt]) tl[cnt] = ++tot;
	build (tl[cnt], l, mid);
	if (!tr[cnt]) tr[cnt] = ++tot;
	build (tr[cnt], mid + 1, r);
	updata (cnt);
}

void pushdown (int cnt) {
	node[tl[cnt]].sum += node[cnt].lazy_add * (node[tl[cnt]].r - node[tl[cnt]].l + 1);
	node[tr[cnt]].sum += node[cnt].lazy_add * (node[tr[cnt]].r - node[tr[cnt]].l + 1);
	
	node[tl[cnt]].lazy_add += node[cnt].lazy_add;
	node[tr[cnt]].lazy_add += node[cnt].lazy_add;
	
	node[cnt].lazy_add = 0;
}

void change_tree (int cnt, int pos) {
	if (node[cnt].l == pos && pos == node[cnt].r) {
		node[cnt].sum = max (abs (val[rk[pos]] - val[fa[rk[pos]]]), abs (val[rk[pos]] + val[fa[rk[pos]]]));
		return;
	}
	pushdown (cnt);
	int mid = (node[cnt].l + node[cnt].r) / 2;
	if (pos <= mid) change_tree (tl[cnt], pos);
	if (pos > mid) change_tree (tr[cnt], pos);
	updata (cnt);
}


void change (int u, int c) {
	val[u] = c;
	change_tree (0, dfn[u]);
	for (auto it : adj[u]) {
		if (it == fa[u]) continue;
		change_tree (0, dfn[it]);
	}
}

ll get_sum (int cnt, int l, int r) {
	if (node[cnt].l >= l && node[cnt].r <= r) {
		return node[cnt].sum;
	}
	ll res = 0;
	pushdown (cnt);
	int mid = (node[cnt].l + node[cnt].r) / 2;
	if (l <= mid) {
		res += get_sum (tl[cnt], l, r);
	}
	if (r > mid) {
		res += get_sum (tr[cnt], l, r);
	}
	return res;
}

ll get_sum_path (int x, int y) {
	ll res = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] > dep[top[y]]) {
			res += get_sum (0, dfn[top[x]], dfn[x]);
			x = fa[top[x]];
		}
		else {
			res += get_sum (0, dfn[top[y]], dfn[y]);
			y = fa[top[y]];
		}
	}
	if (dep[x] < dep[y]) swap (x, y);
	if (x != y) res += get_sum (0, dfn[y] + 1, dfn[x]);
	return res;
}

void init () {
	
}

void dfs1 (int f, int u, int d) {
	fa[u] = f;
	dep[u] = d;
	siz[u] = 1;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs1 (u, it, d + 1);
		siz[u] += siz[it];
		if (siz[h_son[u]] < siz[it]) {
			h_son[u] = it;
		}
	}
}

//求出 top[x], dfn[x], bottom[x], rk[x]
int dfs2 (int f, int u, int t) {
	top[u] = t;
	dfn[u] = ++tot;
	bottom[u] = tot;
	rk[tot] = u;
	if (h_son[u]) bottom[u] = max (bottom[u], dfs2 (u, h_son[u], t));
	for (auto it : adj[u]) {
		if (it == f || it == h_son[u]) continue;
		bottom[u] = max (bottom[u], dfs2 (u, it, it));
	}
	return bottom[u];
}


void charming () {
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	for (int i = 1 ; i < n; ++i) {
		cin >> u >> v;
		adj[u].pb (v);
		adj[v].pb (u);
	}	
	dfs1 (0, 1, 1);
	dfs2 (0, 1, 1);
	build (0, 1, n);
	int opt, c;
	for (int i = 1 ; i <= m; ++i) {
		cin >> opt;
		if (opt == 1) {
			cin >> u >> c;
			change (u, c);
		}
		else {
			cin >> u >> v;
			cout << get_sum_path (u, v) << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}