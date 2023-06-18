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
	vector <int> a (n);
	int cnt1 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 1) ++cnt1;
	}
	if (2 * cnt1 >= n) cout << ((n - cnt1) & 1) << endl;
	else {
		int ans = 0;
		while (2 * cnt1 < n || ((n - cnt1) & 1)) ++ans, ++cnt1;
		cout << ans << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}