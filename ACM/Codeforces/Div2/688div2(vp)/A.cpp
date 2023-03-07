#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	set <int> s;
	int res = 0;
	for (int i = 0, a; i < n; ++i) cin >> a, s.insert (a);
	for (int i = 0, b; i < m; ++i) {
		cin >> b;
		if (s.count (b)) ++res;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}