#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

struct SegmentTree {
	int n;
	vector <int> mx, lazy;
	
	SegmentTree () {
		this -> n = N;
		mx = vector <int> (N << 2 | 1);
		lazy = vector <int> (N << 2 | 1);
	}
	
	void Pushdown (int rt) {
		if (!lazy[rt]) return;
		mx[rt << 1] += lazy[rt];
		mx[rt << 1 | 1] += lazy[rt];
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt]; 
		lazy[rt] = 0;
	}
	
	void Update (int rt) {
		mx[rt] = max (mx[rt << 1], mx[rt << 1 | 1]);
	}
	
	void Modify (int rt, int l, int r, int ql, int qr, int k) {
		if (ql > qr) return;
		if (l >= ql && r <= qr) {
			mx[rt] += k;
			lazy[rt] += k;
			return;
		}
		int mid = l + r >> 1;
		Pushdown (rt);
		if (ql <= mid) Modify (rt << 1, l, mid, ql, qr, k);
		if (qr > mid) Modify (rt << 1 | 1, mid + 1, r, ql, qr, k);
		Update (rt);
	}
	
	int Query (int rt, int l, int r, int ql, int qr) {
		if (ql > qr) return 0;
		if (l >= ql && r <= qr) return mx[rt];
		Pushdown (rt);
		int mid = l + r >> 1, ans = 0;
		if (ql <= mid) ans = max (ans, Query (rt << 1, l, mid, ql, qr));
		if (qr > mid) ans = max (ans, Query (rt << 1 | 1, mid + 1, r, ql, qr));
		return ans;
	}
};

	
int n, k, A;

void init () {}

void charming () {
	init ();
	cin >> n >> k >> A;
	vector <vector <pair <int, int> > > line (N);
	int sum = 0;
	for (int i = 0, x, y, c; i < n; ++i) {
		cin >> x >> y >> c;
		line[y].emplace_back (make_pair (x, c));
		sum += c;
	}
	vector <int> dp (k + 5);
	SegmentTree Tree;
	for (int x = 1, y; x <= k; ++x) {
		y = k - x;
		Tree.Modify (1, 0, N, 0, x - 1, -A);
		for (auto [px, pc] : line[y]) Tree.Modify (1, 0, N, 0, px, pc);
		Tree.Query (1, 0, N, 2, 2);
		dp[x] = max ({0ll, dp[x - 1], Tree.Query (1, 0, N, 0, x - 1)});
		Tree.Modify (1, 0, N, x, x, dp[x]);
	}
	cout << sum - *max_element (dp.begin (), dp.end ()) << endl;
}

signed main () {
	charming ();
	return 0;
}