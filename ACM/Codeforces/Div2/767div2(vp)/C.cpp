#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1);
	vector <vector <int> > pos (n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]].emplace_back (i);
	}
	int be = 0;
	vector <int> ans;
	while (be < n) {
		int last = be, mex;
		for (int i = 0, id; i <= n + 1; ++i) {
			id = upper_bound (pos[i].begin (), 
			pos[i].end (), be) - pos[i].begin ();
			if (id >= pos[i].size ()) {
				mex = i;
				be = max (be + 1, last);
				break;
			}
			last = max (pos[i][id], last);
		}
		ans.emplace_back (mex);
	}
	cout << ans.size () << endl;
	for (int i = 0; i < ans.size (); ++i) {
		cout << ans[i] << " \n"[i == ans.size () - 1];
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}