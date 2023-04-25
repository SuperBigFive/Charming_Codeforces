#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, w, d, h;

void init () {}

void charming () {
	init ();
	cin >> w >> d >> h;
	int a, b, f, g;
	cin >> a >> b >> f >> g;
	cout << min (min (b + g, d - b + d - g) + abs (a - f), 
	min (a + f, w - a + w - f) + abs (b - g)) + h << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}