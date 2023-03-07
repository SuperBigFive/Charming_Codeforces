#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int n, tot;
int root[maxn << 2], val[maxn << 2];
ll ans[maxn << 2], node[maxn * 40];
int ls[maxn * 40], rs[maxn * 40];

void init () {tot = 0;}

void modify (int &now, int l, int r, int pos) {
	if (!now) now = ++tot;
	node[now] = 1;
	if (l == r) return;
	int mid = l + r >> 1;
	if (pos <= mid) modify (ls[now], l, mid, pos);
	else modify (rs[now], mid + 1, r, pos);
}

void merge (int &now, int x, int y, int l, int r, ll &c1, ll &c2) {
	c1 += (ll) node[ls[y]] * node[rs[x]];
	c2 += (ll) node[ls[x]] * node[rs[y]];
	if (!x || !y) {
		now = x + y;
		return;
	}
	now = ++tot;
	if (l == r) {
		node[now] = node[x] + node[y];
		return;
	}
	int mid = l + r >> 1;
	merge (ls[now], ls[x], ls[y], l, mid, c1, c2);
	merge (rs[now], rs[x], rs[y], mid + 1, r, c1, c2);
	node[now] = node[ls[now]] + node[rs[now]];
}

void build (int cnt, int l, int r) {
	int tmp;
	int mid = l + r >> 1;
	cin >> tmp;
	if (!tmp) {
		build (ls[cnt] = ++tot, l, mid);
		build (rs[cnt] = ++tot, mid + 1, r);
	}
	else val[cnt] = tmp;
}

void dfs (int u) {
	if (!ls[u] && !rs[u]) {
		modify (root[u], 1, n, val[u]);
		return;
	}
	dfs (ls[u]), dfs (rs[u]);
	ll c1 = 0, c2 = 0;
	merge (root[u], root[ls[u]], root[rs[u]], 1, n, c1, c2);
	ans[u] = ans[ls[u]] + ans[rs[u]] + min (c1, c2);
}

void charming () {
	init ();
	cin >> n;
	build (0, 1, n);
	dfs (0);
	cout << ans[0] << endl;
}

signed main () {
	charming ();
	return 0;
}