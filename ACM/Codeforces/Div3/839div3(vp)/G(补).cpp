#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, x, y;

void init () {}

void charming () {
	init ();
	cin >> n >> x >> y;
	vector <int> a (n), mn (n);
	for (auto &it : a) cin >> it;
	sort (a.begin (), a.end ());
	for (int i = 0; i < n; ++i)
	mn[i] = a[i] - i;
	int res = 0, p = 0;
	while (x <= y) {
		while (p < n && mn[p] <= x) ++p;
		if (p >= n) {
			cout << res + y - x << endl;
			return;
		}
		if (x + p >= y) {
			for (int i = 0; i < n; ++i) {
				if (x >= a[i]) ++x, ++res;
				if (x >= y) {
					cout << res << endl;
					return;
				}
			}
		}
		if (p <= n - p) {
			cout << -1 << endl;
			return;
		}
		int gain = p * 2 - n;
		int k = (mn[p] - x - 1) / gain + 1;
		if (x + gain * (k - 1) + p >= y) {
			int l = 0, r = k;
			while (l <= r) {
				int mid = l + r >> 1;
				if (x + gain * mid + p >= y) r = mid - 1, k = mid;
				else l = mid + 1;
			}
		}
		res += k * n;
		x += (p * 2 - n) * k;
	}	
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}