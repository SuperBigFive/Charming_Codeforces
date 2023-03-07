#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, l, r, x, a, b;

void init () {}

void charming () {
	init ();
	cin >> l >> r >> x;
	cin >> a >> b;
	if (a == b) cout << 0 << endl;
	else if (abs (a - b) >= x) cout << 1 << endl;
	else if (r - a >= x && r - b >= x) cout << 2 << endl;
	else if (a - l >= x && b - l >= x) cout << 2 << endl;
	else if (r - a >= x && r - l >= x && b - l >= x) {
		cout << 3 << endl;
	}
	else if (a - l >= x && r - l >= x && r - b >= x) {
		cout << 3 << endl;
	}
	else cout << -1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}