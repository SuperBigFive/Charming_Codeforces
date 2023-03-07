#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {

}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	bool ok = true;
	for (int i = 2; i < n; ++i) {
		int GCD = __gcd (a[i - 1], a[i + 1]);
		if (__gcd (GCD, a[i]) != GCD)
		ok = false;
	}
	cout << (ok ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}