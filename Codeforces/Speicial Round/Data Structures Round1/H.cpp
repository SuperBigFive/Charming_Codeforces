#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, rt, tot;
int node[N << 2], ls[N << 2], rs[N << 2];

void init () {rt = tot = 1;}

void modify (int &cnt, int l, int r, int p, int k) {
	if (!cnt) cnt = ++tot;
	if (l == r) return void (node[cnt] = max (node[cnt], k));
	int mid = l + r >> 1;
	if (p <= mid) modify (ls[cnt], l, mid, p, k);
	else modify (rs[cnt], mid + 1, r, p, k);
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
	vector <int> a (n + 5);
	vector <vector <int> > pos (N);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] <= i) pos[a[i]].emplace_back (i - a[i]);
	}
	int res = 0;
	for (int i = 1, mx; i < N; ++i) {
		vector <pair <int, int> > ins;
		for (auto &it : pos[i]) {
			mx = query (rt, 0, N, 0, it);
			ins.emplace_back (make_pair (it, mx + 1));
		}
		for (auto [p, ans] : ins) {
			modify (rt, 0, N, p, ans);
			res = max (res, ans);
		}
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}