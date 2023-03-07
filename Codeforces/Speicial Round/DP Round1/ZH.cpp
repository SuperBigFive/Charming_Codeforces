#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, rt, tot;
int node[N << 2], ls[N << 2], rs[N << 2];

void init () {
	for (int i = 0; i <= tot; ++i)
	node[i] = ls[i] = rs[i] = 0;
	rt = tot = 1;
}

void modify (int &cnt, int l, int r, int ql, int qr, int k) {
	if (!cnt) cnt = ++tot;
	if (l >= ql && r <= qr) {
		node[cnt] = k;
		return;
	}
	int mid = l + r >> 1;
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, k);
	node[cnt] = max (node[ls[cnt]], node[rs[cnt]]);
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
	vector <int> a (n + 5), sum (n + 5);
	vector <pair <int ,int> > pos (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!pos[a[i]].first) pos[a[i]].first = i;
		else pos[a[i]].second = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (pos[i].first && !pos[i].second) {
			sum[pos[i].first] = 1;
		}
	}
	for (int i = 1; i <= n; ++i)
	sum[i] += sum[i - 1];
	sort (pos.begin (), pos.end ());
	int res = 1;
	for (auto &[l, r] : pos) {
		if (!r) continue;
		int mx = query (rt, 1, N, r + 1, N);
		int ans = mx + 2;
		res = max (res, ans + (r > l + 1));
		modify (rt, 1, N, r, r, ans);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}