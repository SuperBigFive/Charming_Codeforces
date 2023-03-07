#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m, tot;
int a[N], b[N], c[N], siz[N];
int node[N << 2], ls[N << 2], rs[N << 2];

void init () {
	for (int i = 0; i <= tot; ++i)
	node[i] = ls[i] = rs[i] = 0;
	tot = 0;
}

void build (int cnt, int l, int r) {
	if (l == r) {
		node[cnt] = c[b[l] + 1];
		return;
	}
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
	node[cnt] = max (node[ls[cnt]], node[rs[cnt]]);
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	int mid = l + r >> 1, res = -1;
	if (ql <= mid) res = max (res, query (ls[cnt], l, mid, ql, qr));
	if (qr > mid) res = max (res, query (rs[cnt], mid + 1, r, ql, qr));
	return res;
}

void charming () {
	init ();
	cin >> n;
	bool ok = true;
	vector <int> flag (n + 1, 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		cin >> b[i], c[i] = b[i];
		if (a[i] < b[i]) ok = false;
	}
	cin >> m;
	map <int, int> cnt;
	for (int i = 1; i <= m; ++i) {
		cin >> siz[i];
		++cnt[siz[i]];
	}
	if (!ok) {
		cout << "NO" << endl;
		return;
	}
	sort (c + 1, c + 1 + n);
	int len = unique (c + 1, c + 1 + n) - c - 1;
	vector <vector <int> > pos (len);
	for (int i = 1; i <= n; ++i) {
		b[i] = lower_bound (c + 1, c + 1 + len, b[i]) - c - 1;
		if (a[i] > c[b[i] + 1]) pos[b[i]].emplace_back (i);
	}
	build (0, 1, n);
	for (int i = 0, mx; i < len; ++i) {
		if (!pos[i].size ()) continue;
		mx = cnt[c[i + 1]];
		for (int j = 0, k = 0; j < pos[i].size (); j = max (j, k) + 1) {
			if (j < pos[i].size () - 1) {
				k = j;
				while (k < pos[i].size () - 1 &&
				query (0, 1, n, pos[i][k], pos[i][k + 1]) <= c[i + 1]) ++k;
			}
			if (mx <= 0) {
				cout << "NO" << endl;
				return;
			}
			--mx;
		}
	}
	cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}