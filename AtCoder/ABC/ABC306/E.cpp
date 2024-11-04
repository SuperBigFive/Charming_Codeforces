#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, k, q;

void init () {}

void charming () {
	init ();
	cin >> n >> k >> q;
	set <pair <int, int>, less <pair <int, int> > > ins, outs;
	for (int i = 1; i <= k; ++i) ins.insert (make_pair (0, i));
	for (int i = k + 1; i <= n; ++i) outs.insert (make_pair (0, i));
	vector <int> a (n + 5);
	for (int i = 1, x, y, ans = 0; i <= q; ++i) {
		cin >> x >> y;
		pair <int, int> data = make_pair (a[x], x);
		if (k >= n) ans += y - a[x], a[x] = y;
		else if (ins.count (data)) {
			if (y == a[x]) {cout << ans << endl; continue;}
			else if (y >= (*outs.rbegin ()).first) {
				ins.erase (data);
				ins.insert (make_pair (y, x));
				ans += y - a[x];
			} else {
				pair <int, int> ndata = *outs.rbegin ();
				ins.erase (data);
				ins.insert (ndata);
				outs.erase (ndata);
				outs.insert (make_pair (y, x));
				ans += ndata.first - a[x];
			}
		} 
		else if (outs.count (data)) {
			if (y == a[x]) {cout << ans << endl; continue;}
			else if (y <= (*ins.begin ()).first) {
				outs.erase (data);
				outs.insert (make_pair (y, x));
			} else {
				pair <int, int> ndata = *ins.begin ();
				ins.erase (ndata);
				ins.insert (make_pair (y, x));
				outs.erase (data);
				outs.insert (ndata);
				ans += y - ndata.first;
			}
		}
		a[x] = y;
		cout << ans << endl;
	}
}

signed main () {
	charming ();
	return 0;
}