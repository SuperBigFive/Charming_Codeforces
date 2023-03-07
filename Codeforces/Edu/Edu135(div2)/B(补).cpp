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
	if (n == 4) cout << "2 1 3 4" << endl;
	else if (n == 5) cout << "1 2 3 4 5" << endl;
	else if (n & 1) {
		for (int i = 1; i <= n - 5; ++i) {
			cout << (n - 1 - i) << " ";
		}
		cout << "1 2 3 " << n - 1 << " " << n << endl;
	}
	else {
		for (int i = 1; i <= n - 2;  ++i) {
			cout << (n - 1 - i) << " ";
		}
		cout << (n - 1) << " " << n << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}