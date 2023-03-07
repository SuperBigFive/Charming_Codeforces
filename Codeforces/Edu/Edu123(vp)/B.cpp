#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n;

void init () {}

void charming () {
	init ();	
	cin >> n;
	if (!(n & 1)) {
		for (int i = 1; i <= n; ++i) {
			int cnt = n - 1;
			for (int j = 1; j <= n; ++j) {
				if (j == i) cout << n << " ";
				else cout << cnt-- << " ";
			}
			cout << endl;
		}
	}
	else {
		for (int i = 2; i <= n; ++i) {
			int cnt = n - 2;
			cout << n << " ";
			for (int j = 2; j <= n; ++j) {
				if (j == i) cout << n - 1 << " ";
				else cout << cnt-- << " ";
			}
			cout << endl;
		}
		cout << n - 1 << " " << n << " ";
		for (int i = 3; i <= n; ++i) cout << n - i + 1 << " ";
		cout << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}