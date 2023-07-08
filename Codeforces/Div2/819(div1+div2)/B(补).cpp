#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	cin >> n >> m;
	if (n & 1) {
		if (m < n) {
			cout << "No" << endl;
			return;
		}
		cout << "Yes" << endl;
		for (int i = 1; i < n; ++i) cout << 1 << ' ';
		cout << m - n + 1 << endl;
	}
	else {
		if ((m & 1) || m < n) {
			cout << "No" << endl;
			return;
		}
		cout << "Yes" << endl;
		for (int i = 1; i <= n - 2; i += 2) {
			cout << 1 << ' ' << 1 << ' ';
		}
		cout << (m - (n - 2)) / 2 << ' ' << (m - (n - 2)) / 2 << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}