#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

struct Node {
	int sum, mx, cnt_mx, se, lazy;
}node[N << 2];

int t, n, m;

void init () {}

void update (int rt) {
	node[rt].sum = node[rt << 1].sum + node[rt << 1 | 1].sum;
	node[rt].mx = max (node[rt << 1].mx, node[rt << 1 | 1].mx);
	if (node[rt << 1].mx == node[rt << 1 | 1].mx) {
		node[rt].cnt_mx = node[rt << 1].cnt_mx + node[rt << 1 | 1].cnt_mx;
		node[rt].se = max (node[rt << 1].se, node[rt << 1 | 1].se);
	}
	else {
		node[rt].cnt_mx = node[rt << 1].mx > node[rt << 1 | 1].mx ?
		node[rt << 1].cnt_mx : node[rt << 1 | 1].cnt_mx;
		node[rt].se = max (min (node[rt << 1].mx, node[rt << 1 | 1].mx), 
		max (node[rt << 1].se, node[rt << 1 | 1].se));
	}
}

void build (int rt, int l, int r) {
	node[rt].lazy = 0;
	node[rt].se = -INT_MAX;
	if (l == r) {
		cin >> node[rt].mx;
		node[rt].sum = node[rt].mx;
		node[rt].cnt_mx = 1;
		return;
	}
	int mid = l + r >> 1;
	build (rt << 1, l, mid);
	build (rt << 1 | 1, mid + 1, r);
	update (rt);
}

void pushdown (int rt) {
	if (!node[rt].lazy) return;
	int chk = max (node[rt << 1].mx, node[rt << 1 | 1].mx);
	if (node[rt << 1].mx == chk) {
		node[rt << 1].sum += node[rt << 1].cnt_mx * node[rt].lazy;
		node[rt << 1].mx += node[rt].lazy;
		node[rt << 1].lazy += node[rt].lazy;
	} 
	if (node[rt << 1 | 1].mx == chk) {
		node[rt << 1 | 1].sum += node[rt << 1 | 1].cnt_mx * node[rt].lazy;
		node[rt << 1 | 1].mx += node[rt].lazy;
		node[rt << 1 | 1].lazy += node[rt].lazy;
	}
	node[rt].lazy = 0;
}

void modify (int rt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		if (node[rt].mx <= k) return;
		else if (node[rt].se < k) {
			int delta = node[rt].mx - k;
			node[rt].sum -= delta * node[rt].cnt_mx;
			node[rt].mx = k;
			node[rt].lazy -= delta;
			return;
		}
	}
	pushdown (rt);
	int mid = l + r >> 1;
	if (ql <= mid) modify (rt << 1, l, mid, ql, qr, k);
	if (qr > mid) modify (rt << 1 |1 , mid + 1, r, ql, qr, k);
	update (rt);
}

int query_mx (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[rt].mx;
	pushdown (rt);
	int mid = l + r >> 1, res = -INT_MAX;
	if (ql <= mid) res = max (res, query_mx (rt << 1, l, mid, ql, qr));
	if (qr > mid) res = max (res, query_mx (rt << 1 | 1, mid + 1, r, ql, qr));
	return res;
}

int query_sum (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[rt].sum;
	pushdown (rt);
	int mid = l + r >> 1, res = 0;
	if (ql <= mid) res += query_sum (rt << 1, l, mid, ql, qr);
	if (qr > mid) res += query_sum (rt << 1 | 1, mid + 1, r, ql, qr);
	return res;
}

void charming () {
	init ();
	cin >> n >> m;
	build (1, 1, n);
	for (int i = 1, opt, x, y, k; i <= m; ++i) {
		cin >> opt >> x >> y;
		if (opt == 0) {
			cin >> k;
			modify (1, 1, n, x, y, k);
		} else if (opt == 1) cout << query_mx (1, 1, n, x, y) << endl;
		else cout << query_sum (1, 1, n, x, y) << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}