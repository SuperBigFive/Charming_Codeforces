#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, m, rt, tot;
int node[N << 2], lazy[N << 2];
int ls[N << 2], rs[N << 2];

void init () {rt = tot = 1;}

void pushdown (int cnt, int l, int r) {
	if (!lazy[cnt]) return;
	if (!ls[cnt]) ls[cnt] = ++tot;
	if (!rs[cnt]) rs[cnt] = ++tot;
	node[ls[cnt]] += lazy[cnt];
	lazy[ls[cnt]] += lazy[cnt];
	node[rs[cnt]] += lazy[cnt];
	lazy[rs[cnt]] += lazy[cnt];
	lazy[cnt] = 0;
}

void modify (int &cnt, int l, int r, int ql, int qr, int k) {
	if (!cnt) cnt = ++tot;
	if (l >= ql && r <= qr) {
		node[cnt] += k;
		lazy[cnt] += k;
		return;
	}
	pushdown (cnt, l, r);
	int mid = l + r >> 1;
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, k);
	node[cnt] = min (node[ls[cnt]], node[rs[cnt]]);
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	pushdown (cnt, l, r);
	int mid = l + r >> 1, res = INT_MAX;
	if (ql <= mid) res = min (res, query (ls[cnt], l, mid, ql, qr));
	if (qr > mid) res = min (res, query (rs[cnt], mid + 1, r, ql, qr));
	return res;
}

void charming () {
	init ();
	cin >> n >> m;	
	vector <array <int, 3> > seq (n);
	for (auto &it : seq) {
		cin >> it[0] >> it[1] >> it[2];
		if (it[0] == 1) continue;
		++it[0];
	}
	sort (seq.begin (), seq.end (), [] (array <int, 3> &x,
	array <int, 3> &y) {return x[2] < y[2];});
	int res = seq[n - 1][2] - seq[0][2];
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && !query (rt, 1, m, 1, m)) {
			modify (rt, 1, m, seq[j][0], seq[j][1], 1);
			++j;
		}
		if (!query (rt, 1, m, 1, m)) break;
		res = min (res, seq[j - 1][2] - seq[i][2]);
		auto [ql, qr, w] = seq[i];
		modify (rt, 1, m, seq[i][0], seq[i][1], -1);
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}