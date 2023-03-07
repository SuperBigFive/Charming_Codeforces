#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t;

void init () {}

void solve (int n, int m, vector <array <int, 3> > &arr, vector <int> &ans) {
	vector <array <int, 2> > vec_l, vec_r, vec;
	for (auto &it : arr) {
		if (it[2]) vec_r.emplace_back ((array <int, 2>) {it[0], it[1]});
		else if (vec_r.size ()) {
			auto id1 = vec_r.back ()[1], id2 = it[1];
			ans[id1] = ans[id2] = abs (it[0] - vec_r.back ()[0] - 1) / 2 + 1;
			vec_r.pop_back ();
		}
		else vec_l.emplace_back ((array <int, 2>) {it[0], it[1]});
	}
	for (int i = 0; i + 1 < vec_l.size (); i += 2) {
		auto id1 = vec_l[i][1], id2 = vec_l[i + 1][1];
		ans[id1] = ans[id2] = abs (vec_l[i][0] + vec_l[i + 1][0] - 1) / 2 + 1;
	}
	for (int i = vec_r.size () - 1; i - 1 >= 0; i -= 2) {
		auto id1 = vec_r[i][1], id2 = vec_r[i - 1][1];
		ans[id1] = ans[id2] = abs (2 * m - vec_r[i][0] - vec_r[i - 1][0] - 1) / 2 + 1;
	}
	if (vec_l.size () & 1) vec.emplace_back (vec_l.back ());
	if (vec_r.size () & 1) vec.emplace_back (vec_r[0]);
	if (vec.size () >= 2)
	ans[vec[0][1]] = ans[vec[1][1]] = abs (vec[0][0] + 2 * m - vec[1][0]) / 2;
}

void charming () {
	init ();
	int n, m;
	cin >> n >> m;
	vector <int> ans (n, -1);
	vector <array <int, 3> > a (n), b, c;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0];
		a[i][1] = i;
	}
	for (int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		if (ch == 'R') a[i][2] = 1;
		if (a[i][0] & 1) b.emplace_back (a[i]);
		else c.emplace_back (a[i]);
	}
	sort (b.begin (), b.end (), [] (array <int, 3> &x,
	array <int, 3> &y) {return x[0] < y[0];});
	sort (c.begin (), c.end (), [] (array <int, 3> &x,
	array <int, 3> &y) {return x[0] < y[0];});
	solve (b.size (), m, b, ans);
	solve (c.size (), m, c, ans);
	for (int i = 0; i < n; ++i)
	cout << ans[i] << " \n"[i == n - 1];
}


signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}