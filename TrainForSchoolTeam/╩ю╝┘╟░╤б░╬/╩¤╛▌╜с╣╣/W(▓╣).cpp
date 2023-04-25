#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e5 + 5;
const int M = 1e9;

struct Node {
	int l, r, lazy;
	pair <int, int> mn_pos;
	bool operator < (const Node x) const {
		return (this -> mn_pos.first) > x.mn_pos.first;
	}
}node[N << 2];

int n, m;

void init () {}

void pushup (int rt) {
	node[rt].mn_pos = min (node[rt << 1].mn_pos, node[rt << 1 | 1].mn_pos);
}

void build (int rt, int l, int r) {
	node[rt].l = l, node[rt].r = r;
	node[rt].lazy = 0;
	if (l == r) {
		cin >> node[rt].mn_pos.first;
		node[rt].mn_pos.second = l;
		return;
	}
	int mid = l + r >> 1;
	build (rt << 1, l, mid);
	build (rt << 1 | 1, mid + 1, r);
	pushup (rt);
}

void pushdown (int rt) {
	if (!node[rt].lazy) return;
	if (node[rt].lazy > node[rt << 1].mn_pos.first) {
		node[rt << 1].mn_pos.first = node[rt].lazy;
		node[rt << 1].lazy = node[rt].lazy;
	}
	if (node[rt].lazy > node[rt << 1 | 1].mn_pos.first) {
		node[rt << 1 | 1].mn_pos.first = node[rt].lazy;
		node[rt << 1 | 1].lazy = node[rt].lazy;
	}
	node[rt].lazy = 0;
}

void modify (int rt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		if (k > node[rt].mn_pos.first) {
			node[rt].mn_pos.first = k;
			node[rt].lazy = k;
		}
		return;
	}
	pushdown (rt);
	int mid = l + r >> 1;
	if (ql <= mid) modify (rt << 1, l, mid, ql, qr, k);
	if (qr > mid) modify (rt << 1 | 1, mid + 1, r, ql, qr, k);
	pushup (rt);
}

pair <int, int> query (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[rt].mn_pos;
	pushdown (rt);
	int mid = l + r >> 1;
	pair <int, int> res = make_pair (INT_MAX, 0);
	if (ql <= mid) res = min (res, query (rt << 1, l, mid, ql, qr));
	if (qr > mid) res = min (res, query (rt << 1 | 1, mid + 1, r, ql, qr));
	return res;
}

void charming () {
	init ();
	cin >> n;
	build (1, 1, n);	
	cin >> m;
	for (int i = 1, opt, a, b, k, x; i <= m; ++i) {
		cin >> opt >> a >> b >> k;
		if (opt == 1) {
			modify (1, 1, n, a, b, k);
		} else {
			cin >> x;
			vector <int> ans;
			priority_queue <Node> pq;
			pq.push ({a, b, 0, query (1, 1, n, a, b)});
			while (!pq.empty ()) {
				Node cur = pq.top ();
				if (cur.mn_pos.first >= k) break;
				pq.pop ();
				ans.emplace_back (cur.mn_pos.first);
				if (ans.size () >= x) break;
				int ql = cur.l, qr = cur.r, mid = cur.mn_pos.second;
				if (ql < mid) {
					pair <int, int> pl = query (1, 1, n, ql, mid - 1);
					if (pl.first < k) pq.push ({ql, mid - 1, 0, pl});
				}
				if (qr > mid) {
					pair <int, int> pr = query (1, 1, n, mid + 1, qr);
					if (pr.first < k) pq.push ({mid + 1, qr, 0, pr});
				}
			}
			if (ans.size () < x) cout << -1 << endl;
			else {
				sort (ans.begin (), ans.end ());
				for (int i = 0; i < x; ++i)
				cout << ans[i] << " \n"[i == x - 1];
			}
		}
	}
}

signed main () {
	charming ();
	return 0;
}