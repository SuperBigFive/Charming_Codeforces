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
		node[cnt].sum = val[rk[l]];
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
	node[tl[cnt]].sum = node[tl[cnt]].sum + (node[cnt].lazy_add * (node[tl[cnt]].r - node[tl[cnt]].l + 1)) % mod;
	node[tr[cnt]].sum = node[tr[cnt]].sum + (node[cnt].lazy_add * (node[tr[cnt]].r - node[tr[cnt]].l + 1)) % mod;
	
	node[tl[cnt]].lazy_add += node[cnt].lazy_add;
	node[tr[cnt]].lazy_add += node[cnt].lazy_add;
	
	node[cnt].lazy_add = 0;
}

void add1 (int cnt, int l, int r, int k) {
	if (l <= node[cnt].l && r >= node[cnt].r) {
		node[cnt].sum = (node[cnt].sum + (node[cnt].r - node[cnt].l + 1) * k) % mod;
		node[cnt].lazy_add = (node[cnt].lazy_add + k) % mod;
		return;
	}
	pushdown (cnt);
	int mid = (node[cnt].l + node[cnt].r) / 2;
	if (l <= mid) add1 (tl[cnt], l, r, k);
	if (r > mid) add1 (tr[cnt], l, r, k);
	updata (cnt);
}

void add2 (int x, int y, int z) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) {
			add1 (0, dfn[top[y]], dfn[y], z);
			y = fa[top[y]];
		}
		else {
			add1 (0, dfn[top[x]], dfn[x], z);
			x = fa[top[x]];
		}
	}
	if (dep[x] < dep[y]) swap (x, y);
	add1 (0, dfn[y], dfn[x], z);
}

void add3 (int x, int z) {
	add1 (0, dfn[x], bottom[x], z);
}

ll get_sum1 (int cnt, int l, int r) {
	if (node[cnt].l >= l && node[cnt].r <= r) {
		return node[cnt].sum % mod;
	}
	ll res = 0;
	pushdown (cnt);
	int mid = (node[cnt].l + node[cnt].r) / 2;
	if (l <= mid) {
		res = (res + get_sum1 (tl[cnt], l, r)) % mod;
	}
	if (r > mid) {
		res = (res + get_sum1 (tr[cnt], l, r)) % mod;
	}
	return res;
}

ll get_sum2 (int x, int y) {
	ll res = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] > dep[top[y]]) {
			res = (res + get_sum1 (0, dfn[top[x]], dfn[x])) % mod;
			x = fa[top[x]];
		}
		else {
			res = (res + get_sum1 (0, dfn[top[y]], dfn[y])) % mod;
			y = fa[top[y]];
		}
	}
	if (dep[x] < dep[y]) swap (x, y);
	res = (res + get_sum1 (0, dfn[y], dfn[x])) % mod;
	return res;
}

ll get_sum3 (int x) {
	return get_sum1 (0, dfn[x], bottom[x]);
}

void init () {
	
}

//求出 fa[x], dep[x], siz[x], h_son[x]
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
	cin >> n >> m >> root >> mod;
	int u, v;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	for (int i = 1 ; i < n; ++i) {
		cin >> u >> v;
		adj[u].pb (v);
		adj[v].pb (u);
	}	
	dfs1 (0, root, 1);
	dfs2 (0, root, root);
	build (0, 1, n);
	int opt, x, y, z;
	for (int i = 1 ; i <= m; ++i) {
		cin >> opt;
		if (opt == 1) {
			cin >> x >> y >> z;
			add2 (x, y, z);
		}
		else if (opt == 2) {
			cin >> x >> y;
			cout << get_sum2 (x, y) % mod << endl;
		}
		else if (opt == 3) {
			cin >> x >> z;
			add3 (x, z);
		}
		else {
			cin >> x;
			cout << get_sum3 (x) % mod << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}