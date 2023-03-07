#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, tot;
int node[N << 5], ls[N << 5], rs[N << 5];

void init () {
	for (int i = 0; i <= tot; ++i) {
		node[i] = ls[i] = rs[i] = 0;
	}
	tot = 1;
}

void modify (int &cnt, int l, int r, int ql, int qr, int k) {
	if (!cnt) cnt = ++tot;
	if (l >= ql && r <= qr) {
		node[cnt] += k;
		return;
	}
	int mid = l + r >> 1;
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, k);
	node[cnt] = node[ls[cnt]] + node[rs[cnt]];
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	int mid = l + r >> 1, res = 0;
	if (ql <= mid) res += query (ls[cnt], l, mid, ql, qr);
	if (qr > mid) res += query (rs[cnt], mid + 1, r, ql, qr);
	return res;
}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	int mn = -1e9 - 7, mx = 1e9 + 7;
	int res = 0, rt = 1;
	for (auto &it : a) {
		cin >> it;
		int cost_l = query (rt, mn, mx, mn, it - 1);
		int cost_r = query (rt, mn, mx, it + 1, mx);
		res += min (cost_l, cost_r);
		modify (rt, mn, mx, it, it, 1);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}