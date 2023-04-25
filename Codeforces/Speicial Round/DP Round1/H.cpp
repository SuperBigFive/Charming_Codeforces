#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	vector <int> a (6);
	for (auto &it : a) cin >> it;
	sort (a.begin (), a.end ());
	cin >> n;
	vector <int> b (n), p (n);
	vector <array <int, 6> > c (n);
	set <pair <int, int> > s;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		for (int j = 0; j < 6; ++j)
		c[i][j] = b[i] - a[j];
		s.insert (make_pair (c[i][0], i));
	}
	int res = INT_MAX;
	while (true) {
		auto mx = (*s.rbegin ()).first;
		auto id = (*s.rbegin ()).second;
		auto mn = (*s.begin ()).first;
		res = min (res, mx - mn);
		if (p[id] >= 5) break;
		auto del = (*s.find (make_pair (mx, id)));
		s.erase (del);
		s.insert (make_pair (c[id][++p[id]], id));
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}