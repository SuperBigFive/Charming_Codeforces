#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <int> a (n);
	vector <pair <int, int> > d;
	for (auto &it : a) cin >> it;
	for (int i = 0, b; i < n; ++i) {
		cin >> b;
		d.emplace_back (make_pair (a[i], b));
	}
	sort (d.begin (), d.end ());
	for (auto &[a, b] : d) {
		if (a <= k) k += b;
		else break;
	}
	cout << k << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}