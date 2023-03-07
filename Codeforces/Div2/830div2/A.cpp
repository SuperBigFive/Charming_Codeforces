#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;	
	vector <int> a(n + 1), b(n + 1);
	int GCD;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = __gcd (a[i], i);
	}
	GCD = a[1];
	for (int i = 2; i <= n; ++i) {
		GCD = __gcd (GCD, a[i]);
	}
	if (GCD == 1) {
		cout << 0 << endl;
		return;
	}
	int res = INT_MAX;
	for (int i = n; i >= 1; --i) {
		if (__gcd (b[i], GCD) == 1) {
			res = n - i + 1;
			break;
		}
	}
	res = min (3ll, res);
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}