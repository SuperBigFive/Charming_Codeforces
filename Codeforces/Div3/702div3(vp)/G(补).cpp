#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, q;

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	vector <int> a (n + 5), mx (n + 5);
	int gain = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		gain += a[i];
		if (i == 1) mx[i] = gain;
		else mx[i] = max (mx[i - 1], gain);
	}
	auto solve = [&] (int k) -> int {
		int l = 1, r = n, res = n;
		while (l <= r) {
			int mid = l + r >> 1;
			if (mx[mid] >= k) r = mid - 1, res = mid;
			else l = mid + 1;
		}
		return res - 1;
	};
	for (int i = 1, x; i <= q; ++i) {
		cin >> x;
		if (gain <= 0) {
			if (mx[n] < x) cout << -1 << " \n"[i == q];
			else cout << solve (x) << " \n"[i == q];
		}
		else {
			if (x <= mx[n]) cout << solve (x) << " \n"[i == q];
			else {
				int k = (x - mx[n] - 1) / gain + 1;
				cout << k * n + solve (x - k * gain) << " \n"[i == q];
			}
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}