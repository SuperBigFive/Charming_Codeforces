#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 1e9 + 5;

struct SegmentTree {
	int n, tot, root;
	vector <int> mn, ls, rs;
	
	SegmentTree (int n) {
		this -> n = n, this -> tot = this -> root = 1;
		this -> mn = vector <int> (n << 6, INT_MAX);
		this -> ls = this -> rs = vector <int> (n << 6);
	}
	
	void Modify (int &rt, int l, int r, int p, int k) {
		if (!rt) rt = ++tot;
		mn[rt] = min (mn[rt], k);
		if (l == r) return;
		int mid = l + r >> 1;
		if (p <= mid) Modify (ls[rt], l, mid, p, k);
		else Modify (rs[rt], mid + 1, r, p, k);
	}
	
	int Query (int rt, int l, int r, int p) {
		if (r <= p) return mn[rt];
		int mid = l + r >> 1, ans = Query (ls[rt], l, mid, p);
		if (p > mid) ans = min (ans, Query (rs[rt], mid + 1, r, p));
		return ans;
	}
};

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <array <int, 3> > rec;
	for (int i = 0, h, w, d; i < n; ++i) {
		cin >> h >> w >> d;
		rec.emplace_back ((array <int, 3>) {h, w, d});
		rec.emplace_back ((array <int, 3>) {h, d, w});
		rec.emplace_back ((array <int, 3>) {w, h, d});
		rec.emplace_back ((array <int, 3>) {w, d, h});
		rec.emplace_back ((array <int, 3>) {d, h, w});
		rec.emplace_back ((array <int, 3>) {d, w, h});
	}
	sort (rec.begin (), rec.end (), [] (array <int, 3> &x,
	array <int, 3> &y) {return x[0] < y[0];});
	int p = 0, q = 0;
	n *= 6;
	SegmentTree Tree (n);
	while (p < n) {
		q = p;
		if (Tree.Query (1, 0, N, rec[q][1] - 1) < rec[q][2]) {
			cout << "Yes" << endl;
			return;
		}
		while (q + 1 < n && rec[q + 1][0] == rec[q][0]) {
			++q;
			if (Tree.Query (1, 0, N, rec[q][1] - 1) < rec[q][2]) {
				cout << "Yes" << endl;
				return;
			}
		}
		for (int i = p; i <= q; ++i) Tree.Modify (Tree.root, 0, N, rec[q][1], rec[q][2]);
		p = q + 1;
	}
	cout << "No" << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	charming ();
	return 0;
}