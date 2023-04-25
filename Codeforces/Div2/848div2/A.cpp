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
	int sum = 0;
	vector <int> a (n);
	for (auto &it : a) cin >> it, sum += it;
	int res = -INT_MAX;
	for (int i = 0; i < n - 1; ++i) {
		res = max (res, sum - 2 * (a[i] + a[i + 1]));
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}