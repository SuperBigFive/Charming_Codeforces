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
	int ans = 0;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n / 2; ++i) {
		ans = __gcd (ans, abs (a[i] - a[n - i + 1]));
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}