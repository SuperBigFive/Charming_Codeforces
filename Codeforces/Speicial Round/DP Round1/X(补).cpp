#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e5 + 5;

int n, tot;
int node[N << 2], ls[N << 2], rs[N << 2], lazy[N << 2];

void update (int cnt) {node[cnt] = max (node[ls[cnt]], node[rs[cnt]]);}

void pushdown (int cnt, int l, int mid, int r) {
	if (!lazy[cnt]) return;
	node[ls[cnt]] += lazy[cnt];
	node[rs[cnt]] += lazy[cnt];
	lazy[ls[cnt]] += lazy[cnt];
	lazy[rs[cnt]] += lazy[cnt];
	lazy[cnt] = 0;
}

void build (int cnt, int l, int r) {
	if (l == r) {
		node[cnt] = 0;
		return;
	}
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
}

void modify (int cnt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		node[cnt] += k;
		lazy[cnt] += k;
		return;
	}
	int mid = l + r >> 1;
	pushdown (cnt, l, mid, r);
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, k);
	update (cnt);
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	int mid = l + r >> 1, res = -INT_MAX;
	pushdown (cnt, l, mid, r);
	if (ql <= mid) res = max (res, query (ls[cnt], l, mid, ql, qr));
	if (qr > mid) res = max (res, query (rs[cnt], mid + 1, r, ql, qr));
	return res;
}

void init () {tot = 1;}

void charming () {
	init ();
	cin >> n;
	vector <int> h (n + 5), b (n + 5);
	for (int i = 1; i <= n; ++i) cin >> h[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	build (1, 0, n);
	vector <int> stk;
	stk.emplace_back (0);
	int siz = 0;
	for (int i = 1; i <= n; ++i) {
		if (!siz) {
			modify (1, 0, n, stk[siz], i - 1, b[i]);
			int mx = query (1, 0, n, 0, i - 1);
			modify (1, 0, n, i, i, mx);
			stk.emplace_back (i), ++siz;
		}
		else {
			while (siz && h[stk[siz]] > h[i]) {
				modify (1, 0, n, stk[siz - 1], stk[siz] - 1, -b[stk[siz]]);
				stk.pop_back (), --siz;
			}
			modify (1, 0, n, stk[siz], i - 1, b[i]);
			int mx = query (1, 0, n, 0, i - 1);
			modify (1, 0, n, i, i, mx);
			stk.emplace_back (i), ++siz;
		}
	}
	cout << query (1, 0, n, n, n) << endl;
}

signed main () {
	charming ();
	return 0;
}