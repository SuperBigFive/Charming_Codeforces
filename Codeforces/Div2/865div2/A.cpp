#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
mt19937 rnd (random_device {} ());

int t, a, b;

void init () {}

void charming () {
	init ();
	cin >> a >> b;
	int x, y;
	while (true) {
		x = rnd () % ((int) 1e9) + 1;
		y = rnd () % ((int) 1e9) + 1;
		if (__gcd (x, y) == 1 && __gcd (abs (x - a), abs (y - b)) == 1) {
			cout << 2 << endl;
			cout << x << " " << y << endl;
			cout << a << " " << b << endl;
			return;
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}