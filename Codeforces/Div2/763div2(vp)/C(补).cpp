#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

bool check (int k, vector <int> &h) {
	vector <int> H = h;
	for (int i = n - 1, d; i >= 2; --i) {
		if (H[i] < k) return false;
		d = min (h[i] / 3, (H[i] - k) / 3);
		H[i] -= 3 * d, H[i - 1] += d, H[i - 2] += 2 * d;
	}
	for (auto i : H) 
	if (i < k) return false;
	return true;
}

void charming () {
	init ();
	cin >> n;
	vector <int> h (n);
	for (auto &it : h) cin >> it;
	int l = 0, r = INT_MAX, res = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid, h)) l = mid + 1, res = mid;
		else r = mid - 1;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}