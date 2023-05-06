#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	for (int i = 0; i <= n; ++i) {
		if (i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2 == k) {
			cout << "YES" << endl;
			for (int j = 1; j <= i; ++j) cout << 1 << " \n"[j == n];
			for (int j = i + 1; j <= n; ++j) cout << -1 << " \n"[j == n];
			return;
		}
	}
	cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}