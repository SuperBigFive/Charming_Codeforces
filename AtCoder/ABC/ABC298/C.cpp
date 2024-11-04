#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, q;

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	vector <multiset <int> > box (N + 5);
	vector <set <int> > bel (N + 5);
	for (int i = 1, opt, x, y; i <= q; ++i) {
		cin >> opt >> x;
		if (opt == 1) {
			cin >> y;
			box[y].insert (x);
			bel[x].insert (y);
		}
		else if (opt == 2) {
			for (auto &it : box[x]) cout << it << " ";
			cout << endl;
		}
		else {
			for (auto &it : bel[x]) cout << it << " ";
			cout << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}