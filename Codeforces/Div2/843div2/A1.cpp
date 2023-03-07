#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	string s, a, b, c;
	cin >> s, n = s.size (), s = '#' + s;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j + 1 <= n; ++j) {
			a = s.substr (1, i);
			b = s.substr (i + 1, j - i);
			c = s.substr (j + 1);
			if ((b <= a && b <= c) || (b >= a && b >= c)) {
				cout << a << " " << b << " " << c << endl;
				return;
			}
		}
	}
	cout << ":(" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}