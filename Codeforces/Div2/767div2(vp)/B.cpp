#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, l, r, k;

void init () {}

void charming () {
	init ();
	cin >> l >> r >> k;
	if (l == r && l > 1) cout << "YES" << endl;
	else if (l & 1) cout << ((r - l + 1) / 2 >= r - l + 1 - k  ? "YES" : "NO") << endl;
	else cout << ((r - l) / 2 + 1 >= r - l + 1 - k ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}