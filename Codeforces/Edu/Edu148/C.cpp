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
	vector <int> a;
	for (int i = 1, last = -1, val; i <= n; ++i) {
		cin >> val;
		if (val == last) continue;
		else last = val, a.emplace_back (val);
	}
	n = a.size ();
	if (n == 1) return void (cout << 1 << endl);
	int ans = 2;
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] > a[i - 1] && a[i] < a[i + 1]) continue;
		else if (a[i] > a[i + 1] && a[i] < a[i - 1]) continue;
		else ++ans;
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}