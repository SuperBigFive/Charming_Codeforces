#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	if (k == 1) {
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++i)
		cout << i << endl;
		return;
	}
	if (n & 1) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			cout << i + (j - 1) * n << " \n"[j == k];
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}