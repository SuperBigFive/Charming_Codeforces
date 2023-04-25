#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	string s1, s2;
	cin >> s1;
	s2 = s1, reverse (s1.begin (), s1.end ());
	bool ok = (s1 == s2);
	if (ok) {
		cout << 1 << endl;
		return;
	}
	else cout << ((k > 0) ? 2 : 1) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}