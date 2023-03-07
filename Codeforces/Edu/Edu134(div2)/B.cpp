#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m, sx, sy, d;

void init () {

}

void charming () {
	init ();
	cin >> n >> m >> sx >> sy >> d;
	if (n - sx + m - sy <= d) {
		cout << -1 << endl;
		return;
	}
	if (sx - 1 <= d) {
		if (sy - 1 <= d || sx + d >= n) {
			cout << -1 << endl;
			return;
		}
	} 
	if (sy - 1 <= d) {
		if (sx - 1 <= d || sy + d >= m) {
			cout << -1 << endl;
			return;
		}
	}
	if (sx + d >= n) {
		if (sy + d >= m || sx - 1 <= d) {
			cout << -1 << endl;
			return;
		}
	}
	if (sy + d >= m) {
		if (sx + d >= n || sy - 1 <= d) {
			cout << -1 << endl;
			return;
		}
	}
	cout << n + m - 2 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}