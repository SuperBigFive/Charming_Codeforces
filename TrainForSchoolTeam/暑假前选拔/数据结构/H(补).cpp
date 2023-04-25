#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e5 + 5;

struct Node {
	int l, r;
	int sum, mn, cnt_mn, se, old_mn;
	int lazy_mn, lazy_mn_mn, lazy_other, lazy_other_mn;
}node[N << 2];

int n, m;
int a[N];

void init () {}

void update (int rt) {
	node[rt].sum = node[rt << 1].sum + node[rt << 1 | 1].sum;
	node[rt].mn = min (node[rt << 1].mn, node[rt << 1 | 1].mn);
	node[rt].old_mn = min (node[rt << 1].old_mn, node[rt << 1 | 1].old_mn);
	if (node[rt << 1].mn == node[rt << 1 | 1].mn) {
		node[rt].cnt_mn = node[rt << 1].cnt_mn + node[rt << 1 | 1].cnt_mn;
		node[rt].se = min (node[rt << 1].se, node[rt << 1 | 1].se);
	}
	else {
		node[rt].cnt_mn = node[rt << 1].mn < node[rt << 1 | 1].mn ? 
		node[rt << 1].cnt_mn : node[rt << 1 | 1].cnt_mn;
		node[rt].se = min (max (node[rt << 1].mn, node[rt << 1 | 1].mn), 
		min (node[rt << 1].se, node[rt << 1 | 1].se));
	}
}

void build (int rt, int l, int r) {
	node[rt].l = l, node[rt].r = r;
	node[rt].lazy_mn = node[rt].lazy_mn_mn = 0;
	node[rt].lazy_other = 0, node[rt].lazy_other_mn = 0;
	node[rt].se = INT_MAX;
	if (l == r) {
		node[rt].sum = a[l];
		node[rt].mn = a[r];
		node[rt].cnt_mn = 1;
		node[rt].old_mn = a[l];
		return;
	}
	int mid = l + r >> 1;
	build (rt << 1, l, mid);
	build (rt << 1 | 1, mid + 1, r);
	update (rt);
}

void change (int rt, int add_mn, int add_mn_mn, int add_other, int add_other_mn) {
	node[rt].sum += add_mn * node[rt].cnt_mn + (node[rt].r - node[rt].l + 1 - node[rt].cnt_mn) * add_other;
	node[rt].old_mn = min (node[rt].old_mn, node[rt].mn + add_mn_mn);
	node[rt].mn += add_mn;
	if (node[rt].se < INT_MAX) node[rt].se += add_other;
	node[rt].lazy_mn_mn = min (node[rt].lazy_mn_mn, node[rt].lazy_mn + add_mn_mn);
	node[rt].lazy_other_mn = min (node[rt].lazy_other_mn, node[rt].lazy_other + add_other_mn);
	node[rt].lazy_mn += add_mn, node[rt].lazy_other += add_other;
}

void pushdown (int rt) {
	int chk = min (node[rt << 1].mn, node[rt << 1 | 1].mn);
	if (node[rt << 1].mn == chk) {
		change (rt << 1, node[rt].lazy_mn, node[rt].lazy_mn_mn, node[rt].lazy_other, node[rt].lazy_other_mn);
	} else {
		change (rt << 1, node[rt].lazy_other, node[rt].lazy_other_mn, node[rt].lazy_other, node[rt].lazy_other_mn);
	}
	if (node[rt << 1 | 1].mn == chk) {
		change (rt << 1 | 1, node[rt].lazy_mn, node[rt].lazy_mn_mn, node[rt].lazy_other, node[rt].lazy_other_mn);
	} else {
		change (rt << 1 | 1, node[rt].lazy_other, node[rt].lazy_other_mn, node[rt].lazy_other, node[rt].lazy_other_mn);
	}
	node[rt].lazy_mn = node[rt].lazy_mn_mn = node[rt].lazy_other = node[rt].lazy_other_mn = 0;
}

void modify_add (int rt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		node[rt].sum += (r - l + 1) * k;
		node[rt].lazy_mn += k, node[rt].lazy_other += k;
		node[rt].lazy_mn_mn = min (node[rt].lazy_mn_mn, node[rt].lazy_mn);
		node[rt].lazy_other_mn = min (node[rt].lazy_other_mn, node[rt].lazy_other);
		node[rt].mn += k;
		if (node[rt].se < INT_MAX) node[rt].se += k;
		node[rt].old_mn = min (node[rt].old_mn, node[rt].mn);
		return;
	}
	int mid = l + r >> 1;
	pushdown (rt);
	if (ql <= mid) modify_add (rt << 1, l, mid, ql, qr, k);
	if (qr > mid) modify_add (rt << 1 | 1, mid + 1, r, ql, qr, k);
	update (rt);
}

void modify_mx (int rt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		if (k <= node[rt].mn) return;
		else if (k < node[rt].se) {
			int delta = k - node[rt].mn;
			node[rt].sum += delta * node[rt].cnt_mn;
			node[rt].lazy_mn += delta;
			node[rt].mn = k;
			return;
		}
	}
	int mid = l + r >> 1;
	pushdown (rt);
	if (ql <= mid) modify_mx (rt << 1, l, mid, ql, qr, k);
	if (qr > mid) modify_mx (rt << 1 | 1, mid + 1, r, ql, qr, k);
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

int query_mn (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[rt].mn;
	int mid = l + r >> 1, res = INT_MAX;
	pushdown (rt);
	if (ql <= mid) res = min (res, query_mn (rt << 1, l, mid, ql, qr));
	if (qr > mid) res = min (res, query_mn (rt << 1 | 1, mid + 1, r, ql, qr));
	return res;
}

int query_old_mn (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[rt].old_mn;
	int mid = l + r >> 1, res = INT_MAX;
	pushdown (rt);
	if (ql <= mid) res = min (res, query_old_mn (rt << 1, l, mid, ql, qr));
	if (qr > mid) res = min (res, query_old_mn (rt << 1 | 1, mid + 1, r, ql, qr));
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
			modify_mx (1, 1, n, l, r, v);
		} 
		else if (opt == 3) cout << query_mn (1, 1, n, l, r) << endl;
		else cout << query_old_mn (1, 1, n, l, r) << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}