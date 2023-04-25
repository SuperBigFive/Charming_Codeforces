#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e5 + 5;

struct Node {
	int l, r, sum, changes;
	int mx, cnt_mx, se, old_mx, mn, old_mn;
	int lazy_mx, lazy_mx_mx, lazy_mx_mn;
	int lazy_other, lazy_other_mx, lazy_other_mn;
	int lazy_add, lazy_changes;
}node[N << 2];

int n, m;

void init () {}

void update (int rt) {
	node[rt].sum = node[rt << 1].sum + node[rt << 1 | 1].sum;
	node[rt].mx = max (node[rt << 1].mx, node[rt << 1 | 1].mx);
	node[rt].mn = min (node[rt << 1].mn, node[rt << 1 | 1].mn);
	node[rt].old_mx = max (node[rt << 1].old_mx, node[rt << 1 | 1].old_mx);
	node[rt].old_mn = min (node[rt << 1].old_mn, node[rt << 1 | 1].old_mn);
	node[rt].changes = node[rt << 1].changes + node[rt << 1 | 1].changes;
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
	node[rt].lazy_mx = node[rt].lazy_mx_mx = node[rt].lazy_mx_mn = 0;
	node[rt].lazy_other = node[rt].lazy_other_mx = node[rt].lazy_other_mn = 0;
	node[rt].se = -INT_MAX, node[rt].lazy_add = 0;
	if (l == r) {
		cin >> node[rt].sum;
		node[rt].mx = node[rt].mn = node[rt].sum;
		node[rt].old_mx = node[rt].old_mn = node[rt].sum;
		node[rt].cnt_mx = 1;
		return;
	}
	int mid = l + r >> 1;
	build (rt << 1, l, mid);
	build (rt << 1 | 1, mid + 1, r);
	update (rt);
}

void change (int rt, int add_mx, int add_mx_mx, int add_mx_mn, int add_other, 
int add_other_mx, int add_other_mn, int times_changes) {
	node[rt].sum += add_mx * node[rt].cnt_mx + (node[rt].r - node[rt].l + 1 - node[rt].cnt_mx) * add_other;
	node[rt].old_mx = max (node[rt].old_mx, node[rt].mx + add_mx_mx);
	node[rt].old_mn = min (node[rt].old_mn, node[rt].mx + add_mx_mn);
	node[rt].mx += add_mx;
	node[rt].old_mn = min (node[rt].old_mn, node[rt].mn + add_other_mn);
	node[rt].mn += add_other;
	node[rt].mn = min (node[rt].mn, node[rt].mx);
	
	if (node[rt].se > -INT_MAX) node[rt].se += add_other;
	node[rt].lazy_mx_mx = max (node[rt].lazy_mx_mx, node[rt].lazy_mx + add_mx_mx);
	node[rt].lazy_mx_mn = min (node[rt].lazy_mx_mn, node[rt].lazy_mx + add_mx_mn);
	node[rt].lazy_other_mx = max (node[rt].lazy_other_mx, node[rt].lazy_other + add_other_mx);
	node[rt].lazy_other_mn = min (node[rt].lazy_other_mn, node[rt].lazy_other + add_other_mn);
	node[rt].lazy_mx += add_mx, node[rt].lazy_other += add_other;
	
	node[rt].changes += node[rt].cnt_mx * times_changes;
	node[rt].lazy_changes += times_changes;
}

void pushdown (int rt) {
	int chk = max (node[rt << 1].mx, node[rt << 1 | 1].mx);
	if (node[rt << 1].mx == chk) {
		change (rt << 1, node[rt].lazy_mx, node[rt].lazy_mx_mx, node[rt].lazy_mx_mn, 
		node[rt].lazy_other, node[rt].lazy_other_mx, node[rt].lazy_other_mn, node[rt].lazy_changes);
	} else {
		change (rt << 1, node[rt].lazy_other, node[rt].lazy_other_mx, 
		node[rt].lazy_other_mn, node[rt].lazy_other, node[rt].lazy_other_mx, node[rt].lazy_other_mn, 0);
	}
	if (node[rt << 1 | 1].mx == chk) {
		change (rt << 1 | 1, node[rt].lazy_mx, node[rt].lazy_mx_mx, node[rt].lazy_mx_mn, 
		node[rt].lazy_other, node[rt].lazy_other_mx, node[rt].lazy_other_mn, node[rt].lazy_changes);
	} else {
		change (rt << 1 | 1, node[rt].lazy_other, node[rt].lazy_other_mx, 
		node[rt].lazy_other_mn, node[rt].lazy_other, node[rt].lazy_other_mx, node[rt].lazy_other_mn, 0);
	}
	if (node[rt].lazy_add) {
		node[rt << 1].changes += (node[rt << 1].r - node[rt << 1].l + 1) * node[rt].lazy_add;
		node[rt << 1 | 1].changes += (node[rt << 1 | 1].r - node[rt << 1 | 1].l + 1) * node[rt].lazy_add;
		node[rt << 1].lazy_add += node[rt].lazy_add;
		node[rt << 1 | 1].lazy_add += node[rt].lazy_add;
	}
	node[rt << 1].mx = min (node[rt << 1].mx, node[rt].mx);
	node[rt << 1 | 1].mx = min (node[rt << 1 | 1].mx, node[rt].mx);
	node[rt << 1].mn = min (node[rt << 1].mn, node[rt].mx);
	node[rt << 1 | 1].mn = min (node[rt << 1 | 1].mn, node[rt << 1 | 1].mx);
	node[rt << 1].old_mn = min (node[rt << 1].old_mn, node[rt << 1].mn);
	node[rt << 1 | 1].old_mn = min (node[rt << 1 | 1].old_mn, node[rt << 1 | 1].mn);
	node[rt].lazy_mx = node[rt].lazy_mx_mx = node[rt].lazy_mx_mn = node[rt].lazy_other = 
	node[rt].lazy_other_mx = node[rt].lazy_other_mn = node[rt].lazy_changes = node[rt].lazy_add = 0;
}

void modify_add (int rt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		node[rt].sum += (r - l + 1) * k;
		node[rt].lazy_mx += k, node[rt].lazy_other += k;
		node[rt].lazy_mx_mx = max (node[rt].lazy_mx_mx, node[rt].lazy_mx);
		node[rt].lazy_mx_mn = min (node[rt].lazy_mx_mn, node[rt].lazy_mx);
		node[rt].lazy_other_mx = max (node[rt].lazy_other_mx, node[rt].lazy_other);
		node[rt].lazy_other_mn = min (node[rt].lazy_other_mn, node[rt].lazy_other);
		node[rt].mx += k, node[rt].mn += k;
		if (node[rt].se > -INT_MAX) node[rt].se += k;
		node[rt].old_mx = max (node[rt].old_mx, node[rt].mx);
		node[rt].old_mn = min (node[rt].old_mn, node[rt].mn);
		node[rt].changes += node[rt].r - node[rt].l + 1;
		node[rt].lazy_add += 1;
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
			node[rt].lazy_mx_mn = min (node[rt].lazy_mx_mn, node[rt].lazy_mx);
			node[rt].mx = k;
			node[rt].old_mn = min (node[rt].old_mn, k);
			node[rt].changes += node[rt].cnt_mx;
			node[rt].lazy_changes += 1;
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

int query_changes (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[rt].changes;
	int mid = l + r >> 1, res = 0;
	pushdown (rt);
	if (ql <= mid) res += query_changes (rt << 1, l, mid, ql, qr);
	if (qr > mid) res += query_changes (rt << 1 | 1, mid + 1, r, ql, qr);
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

int query_mn (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[rt].mn;
	int mid = l + r >> 1, res = INT_MAX;
	pushdown (rt);
	if (ql <= mid) res = min (res, query_mn (rt << 1, l, mid, ql, qr));
	if (qr > mid) res = min (res, query_mn (rt << 1 | 1, mid + 1, r, ql, qr));
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
	build (1, 1, n);
	for (int i = 1, opt, l, r, k, v, cnt = 0; i <= m; ++i) {
		cin >> opt >> l >> r;
		if (opt == 1) {
			cin >> k;
			modify_add (1, 1, n, l, r, k);
			++cnt;
		} 
		else if (opt == 2) {
			cin >> v;
			modify_mn (1, 1, n, l, r, v);
		} 
		else if (opt == 3) cout << query_sum (1, 1, n, l, r) << endl;
		else if (opt == 4) cout << query_changes (1, 1, n, l, r) << endl;
		else if (opt == 5) cout << query_old_mx (1, 1, n, l, r) << endl;
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