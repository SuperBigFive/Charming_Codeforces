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
	if (n & 1) {
		for (int i = 1; i <= n; ++i)
		cout << 1 << " ";
		cout << endl;
	}
	else {
		if (n == 2) {
			cout << 3 << " " << 1 << endl;
			return;
		}
		cout << 1 << " " << n - 1 << " ";
		for (int i = 3; i <= n - 2; i += 2) {
			cout << n << " " << n << " ";
		}
		cout << n / 2 << " " << n / 2 << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}