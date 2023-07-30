#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, b, c, h;

void init () {}

void charming () {
	init ();
	cin >> b >> c >> h;
	cout << min ((c + h) * 2 + 1, b + (b - 1)) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}