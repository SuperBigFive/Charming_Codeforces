#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, tot;
int node[N << 5], rt[N];
int ls[N << 5], rs[N << 5];

void init () {
	for (int i = 0; i <= tot; ++i)
	node[i] = ls[i] = rs[i] = 0;
	tot = 1;
}

void build (int cnt, int l, int r) {
	if (l == r) return;
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
}

int modify (int pre, int l, int r, int ql, int qr, int k) {
	int cur = ++tot;
	node[cur] = max (k, node[pre]);
	ls[cur] = ls[pre], rs[cur] = rs[pre];
	if (l >= ql && r <= qr) {
		node[cur] = k;
		return cur;
	}
	int mid = l + r >> 1;
	if (ql <= mid) ls[cur] = modify (ls[pre], l, mid, ql, qr, k);
	if (qr > mid) rs[cur] = modify (rs[pre], mid + 1, r, ql, qr, k);
	return cur;
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	int mid = l + r >> 1, res = 0;
	if (ql <= mid && ls[cnt]) res = max (res, query (ls[cnt], l, mid, ql, qr));
	if (qr > mid && rs[cnt]) res = max (res, query (rs[cnt], mid + 1, r, ql, qr));
	return res;
}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5), ans (n + 5);
	build (1, 1, n), build (2, 1, n);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	vector <pair <int, int> > stk;
	vector <int> pre (n + 5);
	for (int i = n; i >= 1; --i) {
		while (stk.size () && a[i] > stk.back ().first) {
			pre[stk.back ().second] = i;
			stk.pop_back ();
		}
		stk.emplace_back (make_pair (a[i], i));
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		ans[i] = query (rt[i - 1], 1, n, 1, a[i]) + 1;
		if (pre[i]) ans[i] = max (ans[i], query (rt[pre[i]], 1, n, 1, a[i]) + 2);
		rt[i] = modify (rt[i - 1], 1, n, a[i], a[i], ans[i]);
		res = max (res, ans[i]);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}