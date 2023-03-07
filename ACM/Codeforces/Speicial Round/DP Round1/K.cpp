#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 1e9 + 7;

int t, n, m, tot;
int node[N << 5], ls[N << 5], rs[N << 5];

void init () {
	for (int i = 0; i <= tot; ++i)
	node[i] = ls[i] = rs[i] = 0;
	tot = 1;
}

void modify (int cnt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		node[cnt] = k;
		return;
	}
	int mid = l + r >> 1;
	if (ql <= mid) {
		if (!ls[cnt]) ls[cnt] = ++tot;
		modify (ls[cnt], l, mid, ql, qr, k);
	}
	if (qr > mid) {
		if (!rs[cnt]) rs[cnt] = ++tot;
		modify (rs[cnt], mid + 1, r, ql, qr, k);
	}
	node[cnt] = node[ls[cnt]] + node[rs[cnt]];
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	int mid = l + r >> 1, res = 0;
	if (ql <= mid && ls[cnt]) res += query (ls[cnt], l, mid, ql, qr);
	if (qr > mid && rs[cnt]) res += query (rs[cnt], mid + 1, r, ql, qr);
	return res;
}

int solve (vector <pair <int, int> > &a) {
	init ();
	map <int, int> cnt;
	set <int> s;
	int siz = a.size (), res = 0;
	if (siz <= 1) return 0;
	sort (a.begin (), a.end (), [] (pair <int, int> &x,
	pair <int, int> &y) {
	if (x.first != y.first) return x.first < y.first;
	return x.second < y.second;});
	vector <int> pre (siz);
	for (int i = 0; i < siz; ++i) {
		++cnt[a[i].first];
		if (cnt[a[i].first] >= 2) s.insert (a[i].first);
		if (a[i].second == 0) pre[i] = pre[max (0ll, i - 1)] + 1;
		else {
			pre[i] = pre[max (0ll, i - 1)];
			modify (1, 1, M, a[i].first, a[i].first, 1);
		}
	}
	for (int i = 0; i < siz; ++i) {
		--cnt[a[i].first];
		if (!cnt[a[i].first] && s.count (a[i].first)) 
		s.erase (a[i].first);
		if (a[i].second == 0) continue;
		res = max (res, query (1, 1, M, a[i].first - pre[i] + 1,
		 a[i].first) + (int) s.size ());
	}
	return res;
}

void charming () {
	init ();
	cin >> n >> m;
	vector <pair <int, int> > a (n + m), b, c;
	for (int i = 0; i < n + m; ++i) {
		cin >> a[i].first;
		a[i].second = (i >= n);
		if (a[i].first < 0) 
		b.emplace_back (make_pair (-a[i].first, a[i].second));
		else c.emplace_back (a[i]);
	}
	cout << solve (b) + solve (c) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}