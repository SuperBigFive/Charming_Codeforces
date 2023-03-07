#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <array <int, 3> > point (n + 5);
	multiset <int> mx_r, mx_c;
	vector <int> sum_r (N), sum_c (N);
	vector <multiset <pair <int, int> > > set_r (N), set_c (N);	
	for (int i = 0; i < 3; ++i) mx_r.insert (0), mx_c.insert (0);
	for (int i = 1, x, y, v; i <= n; ++i) {
		cin >> x >> y >> v;
		point[i][0] = x, point[i][1] = y, point[i][2] = v;
		sum_r[x] += v, sum_c[y] += v;
		set_r[x].insert (make_pair (v, i));
		set_c[y].insert (make_pair (v, i));
	}
	for (int i = 0; i < N; ++i) {
		if (set_r[i].size ()) mx_r.insert (sum_r[i]);
		if (set_c[i].size ()) mx_c.insert (sum_c[i]);
	}
	int res = 0, nres_r = 0, nres_c = 0;
	vector <int> del;
	for (int i = 0; i < 3; ++i) {
		auto it_r1 = mx_r.rbegin (), it_c1 = mx_c.rbegin ();
		del.emplace_back (*it_r1), del.emplace_back (*it_c1);
		nres_r += (*it_r1), nres_c += (*it_c1);
		auto it_r2 = mx_r.find (*it_r1), it_c2 = mx_c.find (*it_c1);
		mx_r.erase (it_r2), mx_c.erase (it_c2);
	}
	res = max ({res, nres_r, nres_c});
	for (int i = 0; i < 3; ++i) {
		mx_r.insert (del[i << 1]);
		mx_c.insert (del[i << 1 | 1]);
	}
	del.clear ();
	for (int i = 0, id, c, nres; i < N; ++i) if (set_r[i].size ()) {
		for (auto [v, id] : set_r[i]) {
			c = point[id][1];
			auto it = mx_c.find (sum_c[c]);
			mx_c.erase (it);
			sum_c[c] -= v;
			mx_c.insert (sum_c[c]);
			del.emplace_back (id);
		}
		nres = sum_r[i];
		vector <int> ndel;
		for (int i = 0; i < 2; ++i) {
			auto it_c1 = mx_c.rbegin ();
			ndel.emplace_back (*it_c1);
			nres += (*it_c1);
			auto it_c2 = mx_c.find (*it_c1);
			mx_c.erase (it_c2);
		}
		for (int i = 0; i < 2; ++i)
		mx_c.insert (ndel[i]);
		res = max (res, nres);
		for (int i = 0, c, v, id; i < del.size (); ++i) {
			id = del[i], c = point[id][1], v = point[id][2];
			auto it = mx_c.find (sum_c[c]);
			mx_c.erase (it);
			sum_c[c] += v;
			mx_c.insert (sum_c[c]);
		}
		del.clear ();
	}
	for (int i = 0, id, r, nres; i < N; ++i) if (set_c[i].size ()) {
		for (auto [v, id] : set_c[i]) {
			r = point[id][0];
			auto it = mx_r.find (sum_r[r]);
			mx_r.erase (it);
			sum_r[r] -= v;
			mx_r.insert (sum_r[r]);
			del.emplace_back (id);
		}
		nres = sum_c[i];
		vector <int> ndel;
		for (int i = 0; i < 2; ++i) {
			auto it_r1 = mx_r.rbegin ();
			ndel.emplace_back (*it_r1);
			nres += (*it_r1);
			auto it_r2 = mx_r.find (*it_r1);
			mx_r.erase (it_r2);
		}
		for (int i = 0; i < 2; ++i)
		mx_r.insert (ndel[i]);
		res = max (res, nres);
		for (int i = 0, r, v, id; i < del.size (); ++i) {
			id = del[i], r = point[id][0], v = point[id][2];
			auto it = mx_r.find (sum_r[r]);
			mx_r.erase (it);
			sum_r[r] += v;
			mx_r.insert (sum_r[r]);
		}
		del.clear ();
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