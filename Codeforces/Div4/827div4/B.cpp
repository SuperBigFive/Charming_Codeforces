#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b + c) {
		cout << "YES" << endl;
		return;
	}
	if (b == a + c) {
		cout << "YES" << endl;
		return;
	}
	if (c == a + b) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}