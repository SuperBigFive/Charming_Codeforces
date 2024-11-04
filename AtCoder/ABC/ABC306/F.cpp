#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e4 + 5;
const int M = 1e2 + 5;
const int MX = 1e6 + 5;

struct SegmentTree {
	int n;
	vector <int> sum;
	
	SegmentTree (int n) {this -> n = n, this -> sum = vector <int> (MX << 2);}
	
	void Modify (int rt, int l, int r, int p, int k) {
		sum[rt] += k;
		if (l == r) return;
		int mid = l + r >> 1;
		if (p <= mid) Modify (rt << 1, l, mid, p, k);
		else Modify (rt << 1 | 1, mid + 1, r, p, k);
	}
	
	int Query (int rt, int l, int r, int p) {
		if (r <= p) return sum[rt];
		int mid = l + r >> 1, ans = Query (rt << 1, l, mid, p);
		if (p > mid) ans += Query (rt << 1 | 1, mid + 1, r, p);
		return ans;
	}
};

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> b;
	vector <vector <int> > a (n + 5, vector <int> (m + 5));
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	cin >> a[i][j], b.emplace_back (a[i][j]);
	sort (b.begin (), b.end ());
	SegmentTree Tree (n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] = lower_bound (b.begin (), b.end (), a[i][j]) - b.begin () + 1;
			Tree.Modify (1, 1, MX, a[i][j], 1);
		}
	}
	ll ans = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) Tree.Modify (1, 1, MX, a[i][j], -1);
		for (int j = 1; j <= m; ++j) ans += j * (n - i) + Tree.Query (1, 1, MX, a[i][j]);
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}
