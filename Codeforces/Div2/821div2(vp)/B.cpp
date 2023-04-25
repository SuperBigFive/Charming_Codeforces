#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, x, y;

void init () {
}

void charming () {
	init ();	
	cin >> n >> x >> y;
	if (x && y || !(x + y)) {
		cout << -1 << endl;
		return;
	}
	x += y;
	if ((n - 1) % x) cout << -1 << endl;
	else {
		for (int i = 1, cur = 0; i < n; ++i) {
			if (!((i - 1) % x)) cur += 1 * (cur == 0) + x * (cur != 0) + (cur == 1);
			cout << cur << " \n"[i == n - 1];
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}