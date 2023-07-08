#include <bits/stdc++.h.>
#define ll long long
#define int ll
#define fi first
#define se second
using namespace std;
const int maxn = 4e5 + 5;

int t, n, tot;
int l[maxn], r[maxn], c[maxn], ans[maxn];
int node[maxn << 2], ls[maxn << 2], rs[maxn << 2], lazy[maxn << 2];
vector <pair <int, pair <int, int> > > color[maxn];
multiset <int> pl, pr;

void init () {
	tot = 0;
	pl.clear (), pr.clear ();
	for (int i = 1; i <= n; ++i) {
		color[i].clear ();
	}
}

void build (int cnt, int l, int r) {
	node[cnt] = lazy[cnt] = 0;
	if (l == r) return;	
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
}

void pushdown (int cnt, int l, int mid, int r) {
	if (!lazy[cnt]) return;
	node[ls[cnt]] += lazy[cnt] * (mid - l + 1);
	node[rs[cnt]] += lazy[cnt] * (r - mid);
	lazy[ls[cnt]] += lazy[cnt];
	lazy[rs[cnt]] += lazy[cnt];
	lazy[cnt] = 0;
}

void modify (int cnt, int l, int r, int ql, int qr, int k) {
	if (l >= ql && r <= qr) {
		node[cnt] += (r - l + 1) * k;
		lazy[cnt] += k;
		return;
	}
	int mid = l + r >> 1;
	pushdown (cnt, l, mid, r);
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, k);
	node[cnt] = node[ls[cnt]] + node[rs[cnt]];
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	int mid = l + r >> 1;
	pushdown (cnt, l, mid, r);
	int res = 0;
	if (ql <= mid) res += query (ls[cnt], l, mid, ql, qr);
	if (qr > mid) res += query (rs[cnt], mid + 1, r, ql, qr);
	return res;
}

void charming () {
	init ();
	cin >> n;
	vector <int> pos;
	for (int i = 1; i <= n; ++i) {
		ans[i] = INT_MAX;
		cin >> l[i] >> r[i] >> c[i];
		pos.emplace_back (l[i]);
		pos.emplace_back (r[i]);
		pr.insert (l[i]), pl.insert (-r[i]);
		color[c[i]].emplace_back (make_pair (i, make_pair (l[i], r[i])));
	}

	for (int i = 1; i <= n; ++i) {
		if (!color[i].size ()) continue;
		for (auto it : color[i]) {
			pr.erase (pr.find (it.se.fi));
			pl.erase (pl.find (-it.se.se));
		}
		for (auto it : color[i]) {
			int mnl = *pl.lower_bound (-it.se.fi);
			int mnr = *pr.lower_bound (it.se.se);
			if (!pl.count (mnl) || -mnl > it.se.fi) mnl = -INT_MAX;
			else mnl *= -1;
			if (!pr.count (mnr) || mnr < it.se.se) mnr = INT_MAX;
			ans[it.fi] = min (it.se.fi - mnl, mnr - it.se.se);
		}
		for (auto it : color[i]) {
			pr.insert (it.se.fi);
			pl.insert (-it.se.se);
		}
	}
	
	for (int i = 1; i <= n; ++i) color[i].clear ();
	
	sort (pos.begin (), pos.end ());
	int m = unique (pos.begin (), pos.end ()) - pos.begin ();
	build (0, 1, n << 1);
	for (int i = 1; i <= n; ++i) {
		l[i] = lower_bound (pos.begin (), pos.begin () + m, l[i]) - pos.begin () + 1;
		r[i] = lower_bound (pos.begin (), pos.begin () + m, r[i]) - pos.begin () + 1;
		modify (0, 1, n << 1, l[i], r[i], 1);
		color[c[i]].emplace_back (make_pair (i, make_pair (l[i], r[i])));
	}
	for (int i = 1; i <= n; ++i) {
		if (!color[i].size ()) continue;
		for (auto it : color[i]) {
			modify (0, 1, n << 1, it.se.fi, it.se.se, -1);
		}
		for (auto it : color[i]) {
			if (query (0, 1, n << 1, it.se.fi, it.se.se) > 0) {
				ans[it.fi] = 0;
				continue;
			}
		}
		for (auto it : color[i]) {
			modify (0, 1, n << 1, it.se.fi, it.se.se, 1);
		}
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}