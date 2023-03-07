#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, a, b;

void init () {}

void charming () {
	init ();
	cin >> n;
	a = 1, b = 0, --n;
	int cur = 2, diff;
	for (int i = 0; n > 0; ++i) {
		diff = min (cur, n);
		if (!((i / 2) & 1)) b += diff;
		else a += diff;
		n -= diff, ++cur;
	}
	cout << a << " " << b << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}