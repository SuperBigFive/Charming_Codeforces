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
	for (auto &it : a) {
		cin >> it;
	}
	int GCD = a[0], mx = a[0];
	for (int i = 1; i < n; ++i) {
		GCD = __gcd (GCD, a[i]);
		mx = max (mx, a[i]);
	}
	cout << mx / GCD << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}