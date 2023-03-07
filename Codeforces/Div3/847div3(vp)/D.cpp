#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 1e9 + 7;

int t, n, rt, tot;
pair <int, int> node[N << 5];
int ls[N << 5], rs[N << 5];

void init () {
	for (int i = 1; i <= tot; ++i) 
	node[i] = make_pair (0, 0), ls[i] = rs[i] = 0;
	rt = tot = 1, node[0].first = INT_MAX;
}

void modify (int &cnt, int l, int r, int p, int k) {
	if (!cnt) cnt = ++tot;
	if (l == r) {
		node[cnt].first += k;
		node[cnt].second = l;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid) modify (ls[cnt], l, mid, p, k);
	else modify (rs[cnt], mid + 1, r, p, k);
	node[cnt] = min (node[ls[cnt]], node[rs[cnt]]);
}

pair <int, int> query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	int mid = l + r >> 1;
	pair <int, int> res;
	res.first = INT_MAX;
	if (ql <= mid && ls[cnt]) res = min (res, query (ls[cnt], l, mid, ql, qr));
	if (qr > mid && rs[cnt]) res = min (res, query (rs[cnt], mid + 1, r, ql, qr));
	return res;
}

int solve (int l, int r, int last) {
	if (l > r) return 0;
	auto [mn, id] = query (rt, 1, M, l, r);
	return solve (l, id - 1, mn) + mn - last + solve (id + 1, r, mn);
}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	map <int, int> cnt;
	for (auto &it : a) {
		cin >> it, ++cnt[it];
		modify (rt, 1, M, it, 1);
	}
	sort (a.begin (), a.end ());
	int m = unique (a.begin (), a.end ()) - a.begin ();
	int res = 0;
	for (int i = 0, j; i < m; i = j + 1) {
		j = i;
		while (j + 1 < m && a[j + 1] == a[i] + j + 1 - i) ++j;
		res += solve (a[i], a[j], 0);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}