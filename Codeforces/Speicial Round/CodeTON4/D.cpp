#include <bits/stdc++.h>
#define ll unsigned long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, q;

void init () {}

void charming () {
	init ();
	cin >> q;
	ll l = 1, r = LLONG_MAX;
	for (int i = 1, opt, a, b, n, nl, nr; i <= q; ++i) {
		cin >> opt >> a >> b;
		if (opt == 1) {
			cin >> n;
			if (n == 1) {
				nl = max ((unsigned long long) 1, l);
				nr = min (a, r);
				if (nl > nr) cout << 0 << " ";
				else {
					cout << 1 << " ";
					l = nl, r = nr;
				}
			}
			else {
				nl = max ((n - 2) * (a - b) + a + 1, l);
				nr = min ((n - 1) * (a - b) + a, r);
				if (nl > nr) cout << 0 << " ";
				else {
					cout << 1 << " ";
					l = nl, r = nr;
				}
			}
		}
		else {
			__int128 L = 1, R = LLONG_MAX / (a - b), k1 = R;
			while (L <= R) {
				__int128 mid = L + R >> 1;
				if ((mid - 1) * (a - b) + a >= l) R = mid - 1, k1 = mid;
				else L = mid + 1;
			}
			L = 1, R = LLONG_MAX / (a - b);
			__int128 k2 = R;
			while (L <= R) {
				__int128 mid = L + R >> 1;
				if ((mid - 1) * (a - b) + a >= r) R = mid - 1, k2 = mid;
				else L = mid + 1;
			}
			if (k1 != k2) cout << -1 << " ";
			else cout << (ll) k1 << " ";
		}
	}
	cout << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}