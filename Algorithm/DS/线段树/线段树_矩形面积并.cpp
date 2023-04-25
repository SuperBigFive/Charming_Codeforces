#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	if (!n) exit (0);
	vector <array <int, 4> > seg;
	for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		++x1;
		if (x1 > x2) continue;
		seg.emplace_back ((array <int, 4>) {x1, x2, y1, 1});
		seg.emplace_back ((array <int, 4>) {x1, x2, y2, -1});
	}
	sort (seg.begin (), seg.end (), [] (array <int, 4> &a,
	array <int, 4> &b) {return a[2] < b[2];});
	
	vector <int> lazy (N << 2);
	vector <pair <int, int> > node (N << 2);
	node[1] = make_pair (0, N);
	
	auto build = [&] (auto && me, int rt, int l, int r) -> void {
		node[rt] = make_pair (0, r - l + 1), lazy[rt] = 0;
		if (l == r) return;
		int mid = l + r >> 1;
		me (me, rt << 1, l, mid);
		me (me, rt << 1 | 1, mid + 1, r);
	};
	
	auto pushup = [&] (int rt) -> void {
		node[rt].first = min (node[rt << 1].first, node[rt << 1 | 1].first);
		if (node[rt << 1].first != node[rt << 1 | 1].first) {
			node[rt].second = (node[rt << 1].first < node[rt << 1 | 1].first ? 
			node[rt << 1].second : node[rt << 1 | 1].second);
		}
		else node[rt].second = node[rt << 1].second + node[rt << 1 | 1].second;
	};
	
	auto pushdown = [&] (int rt) -> void {
		if (!lazy[rt]) return;
		node[rt << 1].first += lazy[rt];
		lazy[rt << 1] += lazy[rt];
		node[rt << 1 | 1].first += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		lazy[rt] = 0;
	};
	
	auto modify = [&] (auto && me, int rt, int l, int r, int ql, int qr, int k) -> void {
		if (l >= ql && r <= qr) {
			node[rt].first += k;
			lazy[rt] += k;
			return;
		}
		pushdown (rt);
		int mid = l + r >> 1;
		if (ql <= mid) me (me, rt << 1, l, mid, ql, qr, k);
		if (qr > mid) me (me, rt << 1 | 1, mid + 1, r, ql, qr, k);
		pushup (rt);
	};
	
	build (build, 1, 1, N);
	int ans = 0, cur = 0, last = 0;
	for (auto &[x1, x2, y, st] : seg) {
		if (node[1].first != 0) cur = N;
		else cur = N - node[1].second;
		ans += cur * (y - last);
		last = y;
		modify (modify, 1, 1, N, x1, x2, st);
	}
	cout << ans << endl;
}

signed main () {
	while (true) charming ();
	return 0;
}