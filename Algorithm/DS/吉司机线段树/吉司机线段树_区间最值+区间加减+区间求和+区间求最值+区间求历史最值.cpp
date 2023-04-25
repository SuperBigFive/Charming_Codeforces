#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e5 + 5;

struct Node {
	int l, r;
	int sum, mx, cnt_mx, se, old_mx;
	int lazy_mx, lazy_mx_mx, lazy_other, lazy_other_mx;
}node[N << 2];

int n, m;
int a[N];

void init () {}

void update (int rt) {
	node[rt].sum = node[rt << 1].sum + node[rt << 1 | 1].sum;
	node[rt].mx = max (node[rt << 1].mx, node[rt << 1 | 1].mx);
	node[rt].old_mx = max (node[rt << 1].old_mx, node[rt << 1 | 1].old_mx);
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
	node[rt].l = l, node[rt].r = r;
	node[rt].lazy_mx = node[rt].lazy_mx_mx = 0;
	node[rt].lazy_other = node[rt].lazy_other_mx = 0;
	node[rt].se = -INT_MAX;
	if (l == r) {
		node[rt].sum = a[l];
		node[rt].mx = a[r];
		node[rt].cnt_mx = 1;
		node[rt].old_mx = a[l];
		return;
	}
	int mid = l + r >> 1;
	build (rt << 1, l, mid);
	build (rt << 1 | 1, mid + 1, r);
	update (rt);
}

void change (int rt, int add_mx, int add_mx_mx, int add_other, int add_other_mx) {
	node[rt].sum += add_mx * node[rt].cnt_mx + (node[rt].r - node[rt].l + 1 - node[rt].cnt_mx) * add_other;
	node[rt].old_mx = max (node[rt].old_mx, node[rt].mx + add_mx_mx);
	node[rt].mx += add_mx;
	if (node[rt].se > -INT_MAX) node[rt].se += add_other;
	node[rt].lazy_mx_mx = max (node[rt].lazy_mx_mx, node[rt].lazy_mx + add_mx_mx);
	node[rt].lazy_other_mx = max (node[rt].lazy_other_mx, node[rt].lazy_other + add_other_mx);
	node[rt].lazy_mx += add_mx, node[rt].lazy_other += add_other;
}

void pushdown (int rt) {
	int chk = max (node[rt << 1].mx, node[rt << 1 | 1].mx);
	if (node[rt << 1].mx == chk) {
		change (rt << 1, node[rt].lazy_mx, node[rt].lazy_mx_mx, node[rt].lazy_other, node[rt].lazy_other_mx);
	} else {
		change (rt << 1, node[rt].lazy_other, node[rt].lazy_other_mx, node[rt].lazy_other, node[rt].lazy_other_mx);
	}
	if (node[rt << 1 | 1].mx == chk) {
		change (rt << 1 | 1, node[rt].lazy_mx, node[rt].lazy_mx_mx, node[rt].lazy_other, node[rt].lazy_other_mx);
	} else {
		change (rt << 1 | 1, node[rt].lazy_other, node[rt].lazy_other_mx, node[rt].lazy_other, node[rt].lazy_other_mx);
	}
	node[rt].lazy_mx = node[rt].lazy_mx_mx = node[rt].lazy_other = node[rt].lazy_other_mx = 0;
}

void modify_add (int rt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		node[rt].sum += (r - l + 1) * k;
		node[rt].lazy_mx += k, node[rt].lazy_other += k;
		node[rt].lazy_mx_mx = max (node[rt].lazy_mx_mx, node[rt].lazy_mx);
		node[rt].lazy_other_mx = max (node[rt].lazy_other_mx, node[rt].lazy_other);
		node[rt].mx += k;
		if (node[rt].se > -INT_MAX) node[rt].se += k;
		node[rt].old_mx = max (node[rt].old_mx, node[rt].mx);
		return;
	}
	int mid = l + r >> 1;
	pushdown (rt);
	if (ql <= mid) modify_add (rt << 1, l, mid, ql, qr, k);
	if (qr > mid) modify_add (rt << 1 | 1, mid + 1, r, ql, qr, k);
	update (rt);
}

void modify_mn (int rt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		if (k >= node[rt].mx) return;
		else if (k > node[rt].se) {
			int delta = node[rt].mx - k;
			node[rt].sum -= delta * node[rt].cnt_mx;
			node[rt].lazy_mx -= delta;
			node[rt].mx = k;
			return;
		}
	}
	int mid = l + r >> 1;
	pushdown (rt);
	if (ql <= mid) modify_mn (rt << 1, l, mid, ql, qr, k);
	if (qr > mid) modify_mn (rt << 1 | 1, mid + 1, r, ql, qr, k);
	update (rt);
}

int query_sum (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[rt].sum;
	int mid = l + r >> 1, res = 0;
	pushdown (rt);
	if (ql <= mid) res += query_sum (rt << 1, l, mid, ql, qr);
	if (qr > mid) res += query_sum (rt << 1 | 1, mid + 1, r, ql, qr);
	return res;
}

int query_mx (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[rt].mx;
	int mid = l + r >> 1, res = -INT_MAX;
	pushdown (rt);
	if (ql <= mid) res = max (res, query_mx (rt << 1, l, mid, ql, qr));
	if (qr > mid) res = max (res, query_mx (rt << 1 | 1, mid + 1, r, ql, qr));
	return res;
}

int query_old_mx (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[rt].old_mx;
	int mid = l + r >> 1, res = -INT_MAX;
	pushdown (rt);
	if (ql <= mid) res = max (res, query_old_mx (rt << 1, l, mid, ql, qr));
	if (qr > mid) res = max (res, query_old_mx (rt << 1 | 1, mid + 1, r, ql, qr));
	return res;
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build (1, 1, n);
	for (int i = 1, opt, l, r, k, v; i <= m; ++i) {
		cin >> opt >> l >> r;
		if (opt == 1) {
			cin >> k;
			modify_add (1, 1, n, l, r, k);
		} 
		else if (opt == 2) {
			cin >> v;
			modify_mn (1, 1, n, l, r, v);
		} 
		else if (opt == 3) cout << query_sum (1, 1, n, l, r) << endl;
		else if (opt == 4) cout << query_mx (1, 1, n, l, r) << endl;
		else cout << query_old_mx (1, 1, n, l, r) << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}