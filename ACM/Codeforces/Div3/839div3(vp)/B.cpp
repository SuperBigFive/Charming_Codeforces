#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	array <int, 4> a, b;
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	int cnt = 0;
	while (cnt < 4) {
		if (a[0] < a[1] && a[0] < a[2] && a[1] < a[3] && a[2] < a[3]) {
			cout << "YES" << endl;
			return;
		}
		b[0] = a[2], b[1] = a[0], b[2] = a[3], b[3] = a[1];
		a[0] = b[0], a[1] = b[1], a[2] = b[2], a[3] = b[3];
		++cnt;
	}
	cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}