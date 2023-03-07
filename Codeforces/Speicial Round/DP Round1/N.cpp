#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;
const int M = 1e3 + 5;

int r, n;

void init () {}

void charming () {
	init ();
	cin >> r >> n;
	vector <int> ans (n);
	vector <array <int, 3> > a (n);
	for (auto &it : a) cin >> it[0] >> it[1] >> it[2];
	auto check = [&] (array <int, 3> &x, array <int, 3> &y) -> bool {
		return abs (x[1] - y[1]) + abs (x[2] - y[2]) <= abs (x[0] - y[0]);
	};
	int mx = 0, res = 0;
	for (int i = n - 1; i >= 0; --i) {
		ans[i] = mx + 1;
		for (int j = i + 1; j < min (i + M, n); ++j) {
			if (check (a[i], a[j])) {
				ans[i] = max (ans[i], 1 + ans[j]);
			}
		}
		if (i + M < n) mx = max (mx, ans[i + M]);
	}
	array <int, 3> start = {0, 1, 1};
	for (int i = 0; i < n; ++i) {
		if (check (start, a[i])) 
		res = max (res, ans[i]);
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}