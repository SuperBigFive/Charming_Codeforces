#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, c, d;

void init () {}

void charming () {
	init ();
	cin >> n >> c >> d;
	vector <int> a (n);
	for (auto &it : a) cin >> it;
	sort (a.begin (), a.end (), greater <int> ());
	a.resize (unique (a.begin (), a.end ()) - a.begin ());
	ll add = (n - a.size ()) * c;
	n = a.size ();
	ll res = n * c + d;
	for (int i = 0, remain = 0; i < n; ++i) {
		res = min (res, remain + (a[i] - (n - i)) * d);
		remain += c;
	}
	cout << res + add << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}