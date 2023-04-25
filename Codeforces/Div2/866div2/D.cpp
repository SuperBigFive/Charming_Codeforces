#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

bool check (int h, int w, int hor_cut, int siz,
map <int, multiset <int> > &row, map <int, multiset <int> > &col) {
	if (siz > 0 && (h == 0 || w == 0)) return false;
	else if (siz == 0) {
		if (h == 0 || w == 0) return true;
		else return false;
	}
	else if (siz < 0) return false;
	if (hor_cut) {
		if (!col[w].size ()) return false;
		for (auto nh : col[w]) {
			h -= nh, --siz;
			auto it = row[nh].find (w);
			if (it == row[nh].end ()) return false;
			row[nh].erase (it);
		}
		return check (h, w, hor_cut ^ 1, siz, row, col);
	}
	else {
		if (!row[h].size ()) return false;
		for (auto nw : row[h]) {
			w -= nw, --siz;
			auto it = col[nw].find (h);
			if (it == col[nw].end ()) return false;
			col[nw].erase (it);
		}
		return check (h, w, hor_cut ^ 1, siz, row, col);
	}
}

void charming () {
	init ();
	cin >> n;
	vector <pair <int, int> > mat;
	map <int, multiset <int> > row, col;
	for (int i = 1, h, w; i <= n; ++i) {
		cin >> h >> w;
		mat.emplace_back (make_pair (h, w));
		row[h].insert (w);
		col[w].insert (h);
	}
	
	vector <pair <int, int> > ans;
	int ans_h = 0, ans_w = 0;
	multiset <int> s;
	
	for (auto [h, w] : mat) s.insert (h), ans_w = max (ans_w, w);
	for (auto h : col[ans_w]) {
		ans_h += h;
		auto it = s.find (h);
		s.erase (it);
	}
	if (s.size ()) ans_h += *(s.rbegin ());
	for (auto h : col[ans_w]) {
		s.insert (h);
	}
	if (check (ans_h, ans_w, 1, n, row, col)) {
		ans.emplace_back (make_pair (ans_h, ans_w));
	}
	s.clear ();
	
	ans_h = 0, ans_w = 0;
	row.clear (), col.clear ();
	for (auto [h, w] : mat) {
		s.insert (w), ans_h = max (ans_h, h);
		row[h].insert (w);
		col[w].insert (h);
	}
	for (auto w : row[ans_h]) {
		ans_w += w;
		auto it = s.find (w);
		s.erase (it);
	}
	if (s.size ()) ans_w += *(s.rbegin ());
	for (auto w : row[ans_h]) {
		s.insert (w);
	}
	if (check (ans_h, ans_w, 0, n, row, col)) {
		ans.emplace_back (make_pair (ans_h, ans_w));
	}
	
	if (ans.size () == 2) {
		if (ans[0] == ans[1]) ans.pop_back ();
	}
	cout << ans.size () << endl;
	for (auto [h, w] : ans) cout << h << " " << w << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}