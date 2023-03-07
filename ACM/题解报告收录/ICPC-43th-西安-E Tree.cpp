#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m, tot;
int val[maxn];
int fa[maxn], son[maxn], siz[maxn], dep[maxn];
int dfn[maxn], rk[maxn], top[maxn];
int sum[maxn << 2], lazy_1[maxn << 2], lazy_2[maxn << 2]; 
int ls[maxn << 2], rs[maxn << 2];
vector <int> adj[maxn];

void build (int cnt, int l, int r) {
	lazy_1[cnt] = 0, lazy_2[cnt] = -1;
	if (l == r) {
		sum[cnt] = val[rk[l]];
		return;
	}
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
	sum[cnt] = sum[ls[cnt]] ^ sum[rs[cnt]];
}

void pushdown (int cnt, int l, int mid, int r) {
	if (lazy_2[cnt] != -1) {
		sum[ls[cnt]] &= lazy_2[cnt], sum[rs[cnt]] &=  lazy_2[cnt];
		lazy_2[ls[cnt]] &= lazy_2[cnt], lazy_1[ls[cnt]] &= lazy_2[cnt];
		lazy_2[rs[cnt]] &= lazy_2[cnt], lazy_1[rs[cnt]] &= lazy_2[cnt];
		lazy_2[cnt] = -1;
	}
	if (lazy_1[cnt] != 0){
		if ((mid - l + 1) & 1) sum[ls[cnt]] |= lazy_1[cnt], lazy_1[ls[cnt]] |= lazy_1[cnt];
		else sum[ls[cnt]] -= sum[ls[cnt]] & lazy_1[cnt], lazy_1[ls[cnt]] |= lazy_1[cnt];
		if((r-mid)&1) sum[rs[cnt]] |= lazy_1[cnt],lazy_1[rs[cnt]] |= lazy_1[cnt];
		else sum[rs[cnt]] -= sum[rs[cnt]] & lazy_1[cnt], lazy_1[rs[cnt]] |= lazy_1[cnt]; 
		lazy_1[cnt] = 0;
	}
}

void modify (int cnt, int l, int r, int ql, int qr, int op, int k) {
	if (l >= ql && r <= qr) {
		if (op == 1) {
			if ((r - l + 1) & 1) sum[cnt] |= k;
			else sum[cnt] -= sum[cnt] & k;
			lazy_1[cnt] |= k;
		}
		else {
			sum[cnt] &= k;
			lazy_1[cnt] &= k;
			lazy_2[cnt] &= k;
		}
		return;
	}
	int mid = l + r >> 1;
	pushdown (cnt, l, mid, r);
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, op, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, op, k);
	sum[cnt] = sum[ls[cnt]] ^ sum[rs[cnt]];
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return sum[cnt];
	int mid = l + r >> 1, res = 0;
	pushdown (cnt, l, mid, r);
	if (ql <= mid) res ^= query (ls[cnt], l, mid, ql, qr);
	if (qr > mid) res ^= query (rs[cnt], mid + 1, r, ql, qr);
	return res;
}

void dfs1 (int f, int u, int d) {
	fa[u] = f, siz[u] = 1, dep[u] = d;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs1 (u, it, d + 1);
		siz[u] += siz[it];
		if (siz[it] > siz[son[u]]) son[u] = it;
	}
}

void dfs2 (int f, int u, int tp) {
	dfn[u] = ++tot, rk[tot] = u, top[u] = tp;
	if (son[u]) dfs2 (u, son[u], tp);
	for (auto it : adj[u]) {
		if (it == f || it == son[u]) continue;
		dfs2 (u, it, it);
	}
}

void add_or (int s, int t) {
	while (top[s] != 1) {
		modify (0, 1, n, dfn[top[s]], dfn[s], 1, t);
		s = fa[top[s]];
	}
	modify (0, 1, n, 1, dfn[s], 1, t);
}

void add_and (int s, int t) {
	while (top[s] != 1) {
		modify (0, 1, n, dfn[top[s]], dfn[s], 2, t);
		s = fa[top[s]];
	}
	modify (0, 1, n, 1, dfn[s], 2, t);
}

bool check (int s, int t) {
	int res = 0;
	while (top[s] != 1) {
		res ^= query (0, 1, n, dfn[top[s]], dfn[s]);
		s = fa[top[s]];
	}
	res ^= query (0, 1, n, 1, dfn[s]);
	return res ^ t;
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back (v);
		adj[v].emplace_back (u);
	}
	dfs1 (0, 1, 1), dfs2 (0, 1, 1);
	tot = 0;
	build (0, 1, n);
	for (int i = 1, op, s, t; i <= m; ++i) {
		cin >> op >> s >> t;
		if (op == 1) add_or (s, t);
		else if (op == 2) add_and (s, t);
		else cout << (check (s, t) ? "YES" : "NO") << endl;
	}
	//对于操作1，若区间长度为偶数，则修改为
	// sum = sum - (sum & lazy)
	//若区间长度为奇数，则修改为
	// sum = sum | lazy
	// lazy[son[cnt]] |= lazy[cnt];
	
	// 对于操作2，不论区间长度为奇数偶数，区间异或和直接修改为
	// sum = sum & lazy
	// lazy[son[cnt]] &= lazy[cnt];
}

signed main () {
	charming ();
	return 0;
}