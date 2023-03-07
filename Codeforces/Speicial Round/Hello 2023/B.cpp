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
	if (n & 1) {
		if (n == 3) {
			cout << "NO" << endl;
			return;
		}
		cout << "YES" << endl;
		int s1 = (n - 2) / 2;
		int s2 = (n - 2) / 2 + 1;
		for (int i = 1; i <= n; ++i) {
			if (i & 1) cout << s1 << " ";
			else cout << -s2 << " ";
		}
		cout << endl;
	}
	else {
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++i) {
			if (i & 1) cout << 1 << " ";
			else cout << -1 << " ";
		}
		cout << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}