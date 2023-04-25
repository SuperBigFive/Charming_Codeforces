//#include <bits/stdc++.h>
#include <iostream>
#define ll long long
//#define int ll
using namespace std;
const int N = 1e3 + 5;
const int M = 1e6 + 5;

int opt, n, tot;
int node[M << 3], head[M << 3];
int ls[M << 3], rs[M << 3];

void init () {}

void build (int cnt, int l, int r, bool st) {
	node[cnt] = 0;
	int mid = l + r >> 1;
	if (l != r) {
		build (ls[cnt] = ++tot, l, mid, st);
		build (rs[cnt] = ++tot, mid + 1, r, st);
	}
	if (st) build (head[cnt] = ++tot, 0, n - 1, 0);
}

void modify_y (int cnt_y, int ly, int ry, int y, int k) {
	node[cnt_y] += k;		
	if (ly == ry) return;
	int mid = ly + ry >> 1;
	if (y <= mid) modify_y (ls[cnt_y], ly, mid, y, k);
	else modify_y (rs[cnt_y], mid + 1, ry, y, k);
}

void modify_x (int cnt_x, int lx, int rx, int x, int y, int k) {
	node[cnt_x] += k;
	if (lx == rx) {
		modify_y (head[cnt_x], 0, n - 1, y, k);
		return;
	}
	int mid = lx + rx >> 1;
	if (x <= mid) modify_x (ls[cnt_x], lx, mid, x, y, k);
	else modify_x (rs[cnt_x], mid + 1, rx, x, y, k);
	modify_y (head[cnt_x], 0, n - 1, y, k);
}

int query_y (int cnt_y, int ly, int ry, int qb, int qt) {
	if (ly >= qb && ry <= qt) return node[cnt_y];
	int mid = ly + ry >> 1, res = 0;
	if (qb <= mid) res += query_y (ls[cnt_y], ly, mid, qb, qt);
	if (qt > mid) res += query_y (rs[cnt_y], mid + 1, ry, qb, qt);
	return res;
}

int query_x (int cnt_x, int lx, int rx, int ql, int qr, int qb, int qt) {
	if (lx >= ql && rx <= qr) return query_y (head[cnt_x], 0, n - 1, qb, qt);
	int mid = lx + rx >> 1, res = 0;
	if (ql <= mid) res += query_x (ls[cnt_x], lx, mid, ql, qr, qb, qt);
	if (qr > mid) res += query_x (rs[cnt_x], mid + 1, rx, ql, qr, qb, qt);
	return res;
}

void charming () {
	init ();
	cin >> opt >> n;
	int x, y, a, l, r, b, t;
	build (0, 0, n - 1, 1);
	while (true) {
		cin >> opt;
		if (opt == 1) {
			cin >> x >> y >> a;
			modify_x (0, 0, n - 1, x, y, a);
		}
		else if (opt == 2) {
			cin >> l >> b >> r >> t;
			cout << query_x (0, 0, n - 1, l, r, b, t) << endl;
		}
		else break;
	}
}

signed main () {
	charming ();
	return 0;
}