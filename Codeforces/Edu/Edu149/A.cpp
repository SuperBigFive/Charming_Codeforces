#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, x, k;

void init () {}

void charming () {
	init ();
	cin >> x >> k;
	if (x % k) {
		cout << 1 << endl << x << endl;
	}
	else {
		cout << 2 << endl << x + 1 << " " << -1 << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}