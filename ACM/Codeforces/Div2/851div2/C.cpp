#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	if (!(n & 1)) return void (cout << "No" << endl);
	cout << "Yes" << endl;
	int x = 3 * (n + 1) / 2, y = x + n - 1;
	for (int i = y - n * 2; i >= 1; --i)
	cout << i << " " << 2 * n - (y - n * 2 - i) << endl;
	x = y - n * 2 + 1, y = x + (2 * n - 2 * (x - 1)) - 1;
	for (int i = x; i <= (x + y) / 2; ++i)
	cout << i << " " << i + (y - x + 1) / 2 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}