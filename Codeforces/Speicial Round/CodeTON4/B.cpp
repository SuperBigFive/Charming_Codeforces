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
	if ((n & 1) == 0) {cout << -1 << endl; return;}
	vector <int> d;
	while (n) {
		d.emplace_back (n & 1);
		n >>= 1;
	}
	reverse (d.begin (), d.end ());
	vector <int> ans;
	ans.emplace_back (2);
	for (int i = 1; i < d.size () - 1; ++i) {
		if (d[i] == 1) ans.emplace_back (2);
		else ans.emplace_back (1);
	}
	cout << ans.size () << endl;
	for (auto &it : ans) cout << it << " ";
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}