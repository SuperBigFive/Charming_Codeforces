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
	int id = -1, id1 = -1, id2 = -1;
	for (int i = 2; i < n; ++i) {
		if (s[i] == 'a') id1 = i;
		else id2 = i;
	}
	if (id1 != -1) {
		a = s.substr (1, id1 - 1);
		b = s.substr (id1, 1);
		c = s.substr (id1 + 1);
	}
	else a = s[1], b = s.substr (2, n - 2), c = s[n];
	cout << a << " " << b << " " << c << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}