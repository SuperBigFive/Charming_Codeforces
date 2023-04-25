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

int query_less_k (vector <int> root_l, vector <int> root_r, int l, int r, int k) {
	if (r < k) {
		int sum_l= 0, sum_r = 0;
		for (auto &it : root_l)
		sum_l += node[it];
		for (auto &it : root_r)
		sum_r += node[it];
		return sum_r - sum_l;
	}
	int mid = l + r >> 1;
	vector <int> old_root_l = root_l, old_root_r = root_r;
	for (auto &it : root_l)
	it = ls[it];
	for (auto &it : root_r)
	it = ls[it];
	int res = query_less_k (root_l, root_r, l, mid, k);
	if (k > mid + 1) {
		for (auto &it : old_root_l)
		it = rs[it];
		for (auto &it : old_root_r)
		it = rs[it];
		res += query_less_k (old_root_l, old_root_r, mid + 1, r, k);
	}
	return res;
}

int query_kth (vector <int> &root_l, vector <int> &root_r, int l, int r, int k) {
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
		return query_kth (root_l, root_r, l, mid, k);
	}
	else {
		k -= (sum_r - sum_l);
		for (auto &it : root_l)
		it = rs[it];
		for (auto &it : root_r)
		it = rs[it];
		return query_kth (root_l, root_r, mid + 1, r, k);
	}
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build (1, 1, n);
	for (int i = 1, opt, l, r, k, pos; i <= m; ++i) {
		cin >> opt;
		if (opt == 1) {
			cin >> l >> r >> k;
			vector <int> root_l, root_r;
			get_root (root_l, 1, 1, n, 1, l - 1);
			get_root (root_r, 1, 1, n, 1, r);
			cout << query_less_k (root_l, root_r, 0, M, k) << endl;
		} else if (opt == 2) {	
			cin >> l >> r >> k;
			vector <int> root_l, root_r;
			get_root (root_l, 1, 1, n, 1, l - 1);
			get_root (root_r, 1, 1, n, 1, r);
			cout << query_kth (root_l, root_r, 0, M, k) << endl;
		} else {
			cin >> pos >> k;
			modify (1, 1, n, pos, k);
			a[pos] = k;
		}
	}
}

signed main () {
	charming ();
	return 0;
}