#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e6 + 5;

int n, tot;
pair <int, int> node[N << 2];
int ls[N << 2], rs[N << 2];
vector <pair <int, int> > a;

void init () {tot = 1; node[0] = {INT_MAX, 0};}

void build (int cnt, int l, int r) {
	if (l == r) {
		node[cnt].first = node[cnt].second = a[l].first;
		return;
	}
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
	node[cnt].first = min (node[ls[cnt]].first, node[rs[cnt]].first);
	node[cnt].second = max (node[ls[cnt]].second, node[rs[cnt]].second);
}

pair <int, int> query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	int mid = l + r >> 1, mn = INT_MAX, mx = 0;
	if (ql <= mid) {
		auto [nmn, nmx] = query (ls[cnt], l, mid, ql, qr);
		mn = min (mn, nmn), mx = max (mx, nmx);
	}
	if (qr > mid) {
		auto [nmn, nmx] = query (rs[cnt], mid + 1, r, ql, qr);
		mn = min (mn, nmn), mx = max (mx, nmx);
	}
	return make_pair (mn, mx);
}

void charming () {
	init ();
	cin >> n;
	a.resize (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i;
	build (1, 1, n);
	int res = 1;
	for (int i = 1, mx = 0, l = 1, r = 1; i < n; ++i) {
		auto [mn1, mx1] = query (1, 1, n, l, i);
		auto [mn2, mx2] = query (1, 1, n, i + 1, n);
		if (mn2 >= mx1) ++res, l = r = i + 1;
		else r = i + 1;
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}