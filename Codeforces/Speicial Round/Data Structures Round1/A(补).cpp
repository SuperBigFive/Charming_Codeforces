#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e5 + 5;

int n, q, tot;
int node[N << 5], root[N]; 
int ls[N << 5], rs[N << 5];

void init () {}

int modify (int pre, int l, int r, int ql, int qr, int k) {
	int cur = ++tot;
	node[cur] = node[pre] + 1, ls[cur] = ls[pre], rs[cur] = rs[pre];
	if (l >= ql && r <= qr) return cur;
	int mid = l + r >> 1;
	if (ql <= mid) ls[cur] = modify (ls[pre], l, mid, ql, qr, k);
	if (qr > mid) rs[cur] = modify (rs[pre], mid + 1, r, ql, qr, k);
	return cur;
}

int query (int rtl, int rtr, int l, int r, int k) {
	if (l == r) return l;
	int mid = l + r >> 1;
	if (node[ls[rtr]] - node[ls[rtl]] >= k) 
	return query (ls[rtl], ls[rtr], l, mid, k);
	if (node[rs[rtr]] - node[rs[rtl]] >= k)
	return query (rs[rtl], rs[rtr], mid + 1, r, k);
	return 0;
}

void charming () {
	init ();
	cin >> n >> q;
	vector <int> a (n + 5);
	vector <vector <int> > pos (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]].emplace_back (i);
		root[i] = modify (root[i - 1], 1, N, a[i], a[i], 1);
	}
	for (int i = 1, l, r, mx, k, len; i <= q; ++i) {
		cin >> l >> r;
		k = ceil ((double) (r - l + 1) / 2);
		mx = query (root[l - 1], root[r], 1, N, k);
		if (mx == 0) cout << 1 << endl;
		else {
			len = r - l + 1;
			mx = upper_bound (pos[mx].begin (), pos[mx].end (), r) 
			- lower_bound (pos[mx].begin (), pos[mx].end (), l);
			cout << max (1ll, len - (len - mx) * 2) << endl;
		}
	}
}


signed main () {
	charming ();
	return 0;
}