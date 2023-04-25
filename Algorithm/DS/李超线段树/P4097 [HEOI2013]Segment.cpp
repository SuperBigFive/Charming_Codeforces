#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD1 = 39989, MOD2 = 1e9;
const double eps = 1e-9;

struct Segment {
	double a, b;
	Segment () {a = 0, b = 0;}
	double cal (double x) {return a * x + b;}
};

int n, tot;
int node[N << 2];
Segment seg[N];

void init () {}

int cmp1 (int id1, int id2, int x) {
	double y1 = seg[id1].cal (x), y2 = seg[id2].cal (x);
	if (y1 - y2 > eps) return 1;
	else if (y1 - y2 < -eps) return -1;
	else return 0;
}
	
void cmp2 (pair <double, int> &x, pair <double, int> y) {
	if (x.first - y.first > eps) return;
	else if (x.first - y.first < -eps) x = y;
	else if (x.second > y.second) x = y;
	return;
}

void ins (int rt, int l, int r, int id) {
	int &old = node[rt], mid = l + r >> 1;
	if (cmp1 (old, id, mid) == -1) swap (old, id);
	int chk_l = cmp1 (id, old, l), chk_r = cmp1 (id, old, r);
	if (chk_l == 1 || (!chk_l && id < old)) ins (rt << 1, l, mid, id);
	if (chk_r == 1 || (!chk_r && id < old)) ins (rt << 1 | 1, mid + 1, r, id);
}

void insert (int rt, int l, int r, int ql, int qr, int id) {
	if (l >= ql && r <= qr) {ins (rt, l, r, id); return;}
	int mid = l + r >> 1;
	if (ql <= mid) insert (rt << 1, l, mid, ql, qr, id);
	if (qr > mid) insert (rt << 1 | 1, mid + 1, r, ql, qr, id);
}

pair <double, int> query (int rt, int l, int r, int x) {
	pair <double, int> res ({0.0, 0}), sres ({0.0, 0});
	res.first = seg[node[rt]].cal (x), res.second = node[rt];
	if (l == r) return res;
	int mid = l + r >> 1;
	if (x <= mid) sres = query (rt << 1, l, mid, x);
	else sres = query (rt << 1 | 1, mid + 1, r, x);
	cmp2 (res, sres);
	return res;
}

void charming () {
	init ();
	cin >> n;
	int lastans = 0, opt, k, x0, y0, x1, y1;
	pair <double, int> res;
	for (int i = 1; i <= n; ++i) {
		cin >> opt;
		if (opt == 0) {
			cin >> k;
			res = query (1, 1, N, (k + lastans - 1) % MOD1 + 1);
			cout << (lastans = res.second) << endl;
		} else {
			++tot;
			cin >> x0 >> y0 >> x1 >> y1;
			x0 = (x0 + lastans - 1) % MOD1 + 1;
			y0 = (y0 + lastans - 1) % MOD2 + 1;
			x1 = (x1 + lastans - 1) % MOD1 + 1;
			y1 = (y1 + lastans - 1) % MOD2 + 1;
			if (x0 == x1) {
				seg[tot].a = 0, seg[tot].b = max (y0, y1);
				insert (1, 1, N, x0, x1, tot);
			} else {
				double a = 1.0 * (y1 - y0) / (x1 - x0);
				double b = 1.0 * (y0 - x0 * a);
				seg[tot].a = a, seg[tot].b = b;
				insert (1, 1, N, min (x0, x1), max (x0, x1), tot);
			}
		}
	}
}

signed main () {
	charming ();
	return 0;
}