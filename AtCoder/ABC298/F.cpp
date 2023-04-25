#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 4e5 + 5;

int n;

void init () {}


void charming () {
	init ();
	cin >> n;
	vector <int> a;
	vector <array <int, 3> > input;
	for (int i = 1, r, c, x; i <= n; ++i) {
		cin >> r >> c >> x;
		a.emplace_back (r);
		a.emplace_back (c);
		input.emplace_back ((array <int, 3>) {r, c, x});
	}
	sort (a.begin (), a.end ());
	a.resize (unique (a.begin (), a.end ()) - a.begin ());
	vector <int> row_sum (N);
	multiset <int> mx_row;
	vector <vector <pair <int, int> > > col (N);
	for (auto &[r, c, x] : input) {
		r = lower_bound (a.begin (), a.end (), r) - a.begin () + 1;
		c = lower_bound (a.begin (), a.end (), c) - a.begin () + 1;
		row_sum[r] += x;
		col[c].emplace_back (make_pair (r, x));
	}
	int ans = 0;
	for (int i = 1; i < N; ++i) mx_row.insert (row_sum[i]);
	for (int i = 1, col_sum; i < N; ++i) if (col[i].size ()) {
		col_sum = 0;
		for (auto &[r, x] : col[i]) {
			auto it = mx_row.find (row_sum[r]);
			mx_row.erase (it);
			row_sum[r] -= x;
			col_sum += x;
			mx_row.insert (row_sum[r]);
		}
		ans = max (ans, (*mx_row.rbegin ()) + col_sum);
		for (auto &[r, x] : col[i]) {
			auto it = mx_row.find (row_sum[r]);
			mx_row.erase (it);
			row_sum[r] += x;
			mx_row.insert (row_sum[r]);
		}
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}