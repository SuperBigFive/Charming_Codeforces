#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

ll t, x, y;
ll POW2[65];

void init () {}

void charming (int case_cnt) {
	init ();
	cin >> x >> y;
	POW2[0] = 1;
	for (int i = 1; i < 63; ++i) 
	POW2[i] = POW2[i - 1] * 2;
	auto get = [] (int num) -> pair <vector <int>, vector <int> > {
		vector <int> odd, even;
		for (int i = 0; i < 63; ++i) {
			if ((num / POW2[i]) & 1) {
				if (i & 1) odd.emplace_back (i);
				else even.emplace_back (i);
			}
		}
		return make_pair (even, odd);
	};
	pair <vector <int>, vector <int> > dx, dy;
	dx = get (x), dy = get (y);
	if (dx.first.size () != dy.first.size () || 
	dx.second.size () != dy.second.size ()) {
		cout << "Case " << case_cnt << ": " << -1 << endl;
		return;
	}
	int res = 0;
	for (int i = 0; i < dx.first.size (); ++i) 
	res += abs (dx.first[i] - dy.first[i]);
	for (int i = 0; i < dx.second.size (); ++i)
	res += abs (dx.second[i] - dy.second[i]);
	cout << "Case " << case_cnt << ": " << res / 2 << endl;
}

signed main () {
	cin >> t;
	for (int i = 1; i <= t; ++i) charming (i);
	return 0;
}