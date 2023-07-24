#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;
double eps = 1e-9;

struct Seg {
	double k, b;
	Seg (double k = -1, double b = -1) : k (k), b (b) {}
	double Calc (double x) {return k * x + b;}
}seg[N];

struct LiChao_SegmentTree {
	int n;
	vector <int> node;
	
	LiChao_SegmentTree (int n) {
		this -> n = n;
		this -> node = vector <int> (n << 2 | 1);
	}
	
	int Check (int id1, int id2, int x) {
		double y1 = seg[id1].Calc (x), y2 = seg[id2].Calc (x);
		if (y1 - y2 > eps) return 1;
		else if (y1 - y2 < -eps) return -1;
		else return 0; 
	}
	
	void ins (int rt, int l, int r, int id) {
		int mid = l + r >> 1;
		if (Check (id, node[rt], mid) == 1) swap (node[rt], id);
		int chk_l = Check (id, node[rt], l), chk_r = Check (id, node[rt], r);
		if (chk_l == 1 || (!chk_l && id < node[rt])) ins (rt << 1, l, mid, id);
		if (chk_r == 1 || (!chk_r && id < node[rt])) ins (rt << 1 | 1, mid + 1, r, id);
	}
	
	void Insert (int rt, int l, int r, int ql, int qr, int id) {
		if (l >= ql && r <= qr) {ins (rt, l, r, id); return;}
		int mid = l + r >> 1;
		if (ql <= mid) Insert (rt << 1, l, mid, ql, qr, id);
		if (qr > mid) Insert (rt << 1 | 1, mid + 1, r, ql, qr, id);
	}
	
	int Query (int rt, int l, int r, int p) {
		if (l == r) return node[rt];
		int mid = l + r >> 1, ans = node[rt], nans;
		if (p <= mid) nans = Query (rt << 1, l, mid, p);
		else nans = Query (rt << 1 | 1, mid + 1, r, p);
		double y1 = seg[ans].Calc (p), y2 = seg[nans].Calc (p);
		if (y1 - y2 < -eps || (y1 - y2 < eps && nans < ans)) ans = nans;
		return ans;
	}
};


int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	LiChao_SegmentTree LiChao (N);
	for (int i = 1, op, k, x, x0, y0, x1, y1, lans = 0, cnt = 0; i <= n; ++i) {
		cin >> op;
		if (op == 0) {
			cin >> k;
			x = (k + lans - 1) % 39989 + 1;
			lans = LiChao.Query (1, 1, N, x);
			cout << lans << endl;
		}
		else {
			cin >> x0 >> y0 >> x1 >> y1;
			x0 = (x0 + lans - 1) % 39989 + 1;
			x1 = (x1 + lans - 1) % 39989 + 1;
			y0 = (y0 + lans - 1) % (int) 1e9 + 1;
			y1 = (y1 + lans - 1) % (int) 1e9 + 1;
			++cnt;
			if (x0 == x1) seg[cnt] = {0, max (y0, y1)};
			else {
				double k = (1.0 * (y1 - y0)) / (1.0 * (x1 - x0)), b = y0 - k * x0;
				seg[cnt] = {k, b};
			}
			LiChao.Insert (1, 1, N, min (x0, x1), max (x0, x1), cnt);
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	clock_t start;
	charming ();
	return 0;
}