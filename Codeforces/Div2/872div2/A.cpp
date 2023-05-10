#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s, n = s.size ();
	bool ok = false;
	for (int i = 0; i < n; ++i) if (s[i] != s[0]) ok = true;
	if (!ok) cout << -1 << endl;
	else cout << n - 1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}