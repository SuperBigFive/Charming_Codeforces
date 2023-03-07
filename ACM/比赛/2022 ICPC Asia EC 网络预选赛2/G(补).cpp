#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1000000007;

int n, m, tot;
int color[maxn << 2];
int ls[maxn << 2], rs[maxn << 2];
int len[maxn];
ll ans[maxn], fac[maxn];
vector <int> adj[maxn];
pair <int, int> lim[maxn];

void init () {}

void build (int cnt, int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
}

void pushdown (int cnt) {
	if (color[cnt]) {
		color[ls[cnt]] = color[rs[cnt]] = color[cnt];
		color[cnt] = 0;
	}
}

void modify (int cnt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		color[cnt] = k;
		return;
	}
	int mid = (l + r) / 2;
	pushdown (cnt);
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, k);
}

int query (int cnt, int l, int r, int pos) {
	if (l == r) return color[cnt];
	int mid = (l + r) / 2;
	pushdown (cnt);
	if (pos <= mid) return query (ls[cnt], l, mid, pos);
	return query (rs[cnt], mid + 1, r, pos);
}

void get_fac () {
	fac[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
}

void dfs (int f, int u) {
	int sum_len = 0;
	ans[u] = 1;
	for (auto it : adj[u]) {
		if (it == f) continue;
		dfs (u, it);
		sum_len += len[it];
		ans[u] = (ans[u] * ans[it]) % mod;
	}
	int sum = len[u] - sum_len + adj[u].size ();
	ans[u] = ((ans[u] * fac[sum]) % mod + mod) % mod;
}

void charming () {
	init ();
	cin >> n >> m;
	build (0, 1, n);
	for (int i = 1, l, r; i <= m; ++i) {
		cin >> l >> r;
		lim[i].first = l, lim[i].second = r;
	}
	sort (lim + 1, lim + 1 + m, [] (pair <int, int> &a, 
	pair <int, int> &b) {return a.second - a.first > b.second - b.first;});		
	for (int i = 1, l, r; i <= m; ++i) {
		l = lim[i].first, r = lim[i].second;
		adj[query (0, 1, n, (l + r) / 2)].emplace_back (i);
		len[i] = r - l + 1;
		modify (0, 1, n, l, r, i);
	}
	get_fac (), len[0] = n, dfs (0, 0);
	cout << ((ans[0] % mod) + mod) % mod << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}