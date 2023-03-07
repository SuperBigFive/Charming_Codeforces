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
	vector <int> b (n);
	set <int> s;
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		s.insert (b[i]);
		if (!i) continue;
		else if (b[i] == b[i - 1]) continue;
		else if (*s.upper_bound (min (b[i], b[i - 1])) != max (b[i], b[i - 1])) ok = false;
	}
	cout << (ok ? "YES" : "NO") << endl;
}


signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}