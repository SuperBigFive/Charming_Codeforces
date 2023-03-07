#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t;

void init () {}
	
void charming () {
	init ();
	ll k, x, res = 0;
	cin >> k >> x;
	if (k * (k + 1) / 2 <= x) {
		x -= k * (k + 1) / 2 - k;
		res = 2 * k - 1;
		int l = k, r = 2 * k - 1;
		while (l <= r) {
			int mid = l + r >> 1;
			if ((3 * k  - mid) * (mid - k + 1) / 2 < x) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
				res = mid;
			}
		}
	}
	else {
		int l = 1, r = k;
		res = 1;
		while (l <= r) {
			int mid = l + r >> 1;
			if ((mid + 1) * mid / 2 < x) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
				res = mid;
			}
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}