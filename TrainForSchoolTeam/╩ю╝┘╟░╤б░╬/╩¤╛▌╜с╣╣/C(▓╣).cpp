#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 4e7 + 5;
const int M = 1e5 + 5;

int n, m, tot;
int a[N], root[N], node[N], ls[N], rs[N];

void init () {tot = 1;}

void insert (int &rt, int l, int r, int p, int k) {
	if (!rt) rt = ++tot;
	node[rt] += k;
	if (l == r) return;
	int mid = l + r >> 1;
	if (p <= mid) insert (ls[rt], l, mid, p, k);
	else insert (rs[rt], mid + 1, r, p, k);
}

void build (int rt, int l, int r) {
	int mid = l + r >> 1;
	if (l != r) {
		build (ls[rt] = ++tot, l, mid);
		build (rs[rt] = ++tot, mid + 1, r);
	}
	for (int i = l; i <= r; ++i)
	insert (root[rt], 0, M, a[i], 1);
}

void modify (int rt, int l, int r, int p, int v) {
	int mid = l + r >> 1;
	if (l != r) {
		if (p <= mid) modify (ls[rt], l, mid, p, v);
		else modify (rs[rt], mid + 1, r, p, v);
	}
	insert (root[rt], 0, M, a[p], -1);
	insert (root[rt], 0, M, v, 1);
}

void get_root (vector <int> &vec, int rt, int l, int r, int ql, int qr) {
	if (ql > qr) return;
	if (l >= ql && r <= qr) {
	vec.emplace_back (root[rt]); return;}
	int mid = l + r >> 1;
	if (ql <= mid) get_root (vec, ls[rt], l, mid, ql, qr);
	if (qr > mid) get_root (vec, rs[rt], mid + 1, r, ql, qr);
}

int query (vector <int> &root_l, vector <int> &root_r, int l, int r, int k) {
	if (l == r) return l;
	int sum_l = 0, sum_r = 0;
	for (auto it : root_l)
	sum_l += node[ls[it]];
	for (auto it : root_r)
	sum_r += node[ls[it]];
	int mid = l + r >> 1;
	if (sum_r - sum_l >= k) {
		for (auto &it : root_l)
		it = ls[it];
		for (auto &it : root_r)
		it = ls[it];
		return query (root_l, root_r, l, mid, k);
	}
	else {
		k -= (sum_r - sum_l);
		for (auto &it : root_l)
		it = rs[it];
		for (auto &it : root_r)
		it = rs[it];
		return query (root_l, root_r, mid + 1, r, k);
	}
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build (1, 1, n);
	char opt;
	for (int i = 1, l, r, k, x, y; i <= m; ++i) {
		cin >> opt;
		if (opt == 'Q') {
			cin >> l >> r >> k;
			vector <int> root_l, root_r;
			get_root (root_l, 1, 1, n, 1, l - 1);
			get_root (root_r, 1, 1, n, 1, r);
			cout << query (root_l, root_r, 0, M, k) << endl;
		} else {
			cin >> x >> y;
			modify (1, 1, n, x, y);
			a[x] = y;
		}
	}
}

signed main () {
	charming ();
	return 0;
}