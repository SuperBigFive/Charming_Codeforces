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
	vector <int> a (n + 5);
	int ans = INT_MAX, GCD = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] < 0) ans = a[i];
		GCD = __gcd (GCD, a[i]);
	}
	if (ans < 0) cout << ans << endl;
	else cout << *max_element (a.begin () + 1, a.begin () + 1 + n) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}