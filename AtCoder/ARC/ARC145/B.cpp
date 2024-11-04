#include <bits/stdc++.h>
#define ll long long 
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

ll n, a, b;

void charming () {
	cin >> n >> a >> b;
	if (a >= b) {
		if (n < a) {
			cout << 0 << endl;
			return;
		}
		ll res = 0;
		n -= a - 1;
		int d = n / a;
		res += b * d;
		n -= a * d;
		res += max ((ll) 0, min (b, n));
		cout << res << endl;
	}
	else {
		if (n < a) {
			cout << 0 << endl;
			return;
		}
		cout << n - a + 1 << endl;
	}
}

signed main () {
	charming ();
	return 0;
}