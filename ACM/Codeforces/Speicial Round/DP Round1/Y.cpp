#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	auto check = [&] (int mid) -> bool {
		vector <int> pre (n + 5);
		int mn = 0;
		for (int i = 1; i <= n; ++i) {
			pre[i] = pre[i - 1];
			if (a[i] >= mid) ++pre[i];
			else --pre[i];
		}
		for (int i = k; i <= n; ++i) {
			mn = min (mn, pre[i - k]);
			if (pre[i] > mn) return true;
		}
		return false;
	};
	int l = 1, r = n, res = 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid)) l = mid + 1, res = mid;
		else r = mid - 1;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}