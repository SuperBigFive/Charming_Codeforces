#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5), b;
	string s;
	cin >> s, s = '#' + s;
	for (int i = 1, mx = 0, ok = false; i <= n; ++i) {
		cin >> a[i];
		if (i > 1 && s[i] != s[i - 1]) {
			if (!ok) ok = true, mx = 0;
			else {
				b.emplace_back (mx);
				mx = 0;
			}
		}
		mx = max (a[i], mx);
	}
	sort (b.begin (), b.end (), greater <int> ());
	if (!b.size ()) return void (cout << 0 << endl);
	ll res = 0;
	for (int i = 0; i < ((int)b.size () - 1) / 2 + 1; ++i)
	res += b[i];
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}