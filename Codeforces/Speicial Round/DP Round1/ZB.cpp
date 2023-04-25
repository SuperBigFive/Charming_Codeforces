#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e5 + 5;

int n, tot, rt1, rt2;
int node[N << 5], ls[N << 5], rs[N << 5];

void init () {rt1 = 1, rt2 = 2, tot = 2;}

void build (int cnt, int l, int r) {
	if (l == r) {
		node[cnt] = INT_MAX;
		return;
	}
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
}

void modify (int cnt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		node[cnt] = k;
		return;
	}
	int mid = l + r >> 1;
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, k);
	node[cnt] = min (node[ls[cnt]], node[rs[cnt]]);
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	int mid = l + r >> 1, res = INT_MAX;
	if (ql <= mid) res = min (res, query (ls[cnt], l, mid, ql, qr));
	if (qr > mid) res = min (res, query (rs[cnt], mid + 1, r, ql, qr));
	return res;
}

void charming () {
	init ();
	cin >> n;
	vector <int> h (n + 5);
	for (int i = 1; i <= n; ++i) cin >> h[i];
	build (rt1, 1, n), build (rt2, 1, n);
	vector <int> stk_inc, stk_dec, ans (n + 5);
	stk_inc.emplace_back (h[n]), stk_dec.emplace_back (h[n]);
	int siz_inc = 1, siz_dec = 1;
	ans[n + 1] = -1;
	for (int i = n, id_inc, id_dec; i >= 1; --i) {
		ans[i] = ans[i + 1] + 1;
		if (i < n) {
			if (h[i] >= h[i + 1]) {
				id_inc = upper_bound (stk_inc.begin (), stk_inc.end (), h[i],
				[] (int x, int y) {return x > y;}) - stk_inc.begin ();
				id_inc = max (1ll, id_inc);
				ans[i] = min (ans[i], query (rt1, 1, n, id_inc, siz_inc) + 1);
			}
			else {
				id_dec = upper_bound (stk_dec.begin (), 
				stk_dec.end (), h[i]) - stk_dec.begin ();
				id_dec = max (1ll, id_dec);
				ans[i] = min (ans[i], query (rt2, 1, n, id_dec, siz_dec) + 1);
			}
		}
		while (siz_inc && h[i] >= stk_inc.back ()) {
			modify (rt1, 1, n, siz_inc, siz_inc, INT_MAX);
			stk_inc.pop_back (), --siz_inc;
		}
		while (siz_dec && h[i] <= stk_dec.back ()) {
			modify (rt2, 1, n, siz_dec, siz_dec, INT_MAX);
			stk_dec.pop_back (), --siz_dec;
		}
		stk_inc.emplace_back (h[i]), ++siz_inc;
		modify (rt1, 1, n, siz_inc, siz_inc, ans[i]);
		stk_dec.emplace_back (h[i]), ++siz_dec;
		modify (rt2, 1, n, siz_dec, siz_dec, ans[i]);
	}
	cout << ans[1] << endl;
}

signed main () {
	charming ();
	return 0;
}