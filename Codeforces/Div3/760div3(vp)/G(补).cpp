#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m, q;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> q;
	vector <int> a (n), b (m);
	vector <pair <int, int> > query (q);
	for (auto &it : a) cin >> it;
	for (auto &it : b) cin >> it;
	for (int i = 0; i < q; ++i) {
		cin >> query[i].first;
		query[i].second = i;
	}
	sort (a.begin (), a.end ());
	sort (b.begin (), b.end ());
	sort (query.begin (), query.end ());
	vector <int> pre (n + m), siz (n + m), ans (n + m);
	vector <vector <int> > elem (n + m);
	vector <pair <int, pair <int, int> > > edge;
	for (int i = 0; i < n + m; ++i) {
		pre[i] = i, siz[i] = i < n;
		ans[i] = (i < n ? a[i] : 0);
		if (i < n) elem[i].emplace_back (a[i]);
		else elem[i].emplace_back (b[i - n]);
	}
	for (int i = 0, id; i < n; ++i) {
		id = lower_bound (b.begin (), b.end (), a[i]) - b.begin ();
		if (id < m)
		edge.emplace_back (make_pair (b[id] - a[i], make_pair (i, n + id)));
		if (i < n - 1)
		edge.emplace_back (make_pair (a[i + 1] - a[i], make_pair (i, i + 1)));
	}
	for (int i = 0, id; i < m; ++i) {
		id = lower_bound (a.begin (), a.end (), b[i]) - a.begin ();
		if (id < n)
		edge.emplace_back (make_pair (a[id] - b[i], make_pair (id, n + i)));
		if (i < m - 1)
		edge.emplace_back (make_pair (b[i + 1] - b[i], make_pair (n + i, n + i + 1)));
	}	
	sort (edge.begin (), edge.end (), [] (pair <int, pair <int, int> > &x,
	pair <int, pair <int, int> > &y) {return x.first < y.first;});
	auto find = [&] (auto &&me, int x) -> int {
		if (x == pre[x]) return x;
		pre[x] = me (me, pre[x]);
		return pre[x];
	};
	int p = 0;
	ll mx = 0;
	vector <int> res (q);
	for (auto &it : a) mx += it;
	for (auto &[k, id] : query) {
		while (p < edge.size () && edge[p].first <= k) {
			int u = edge[p].second.first, v = edge[p].second.second;
			int fu = find (find, u), fv = find (find, v);
			if (fu == fv) {++p; continue;}
			if (elem[fu][0] > elem[fv][0]) swap (fu, fv);
			pre[fu] = fv;
			int p1 = 0, p2 = 0;
			ll nans = ans[fv];
			vector <int> nelem;
			for (int i = 0; i < elem[fu].size (); ++i)
			elem[fv].emplace_back (elem[fu][i]);
			for (int i = siz[fv]; i < siz[fv] + siz[fu]; ++i)
			nans += elem[fv][i];
			siz[fv] += siz[fu];
			mx += nans - ans[fu] - ans[fv];
			ans[fv] = nans;
			++p;
		}
		res[id] = mx;
	}
	for (int i = 0; i < q; ++i) cout << res[i] << endl;
}

signed main () {
	charming ();
	return 0;
}