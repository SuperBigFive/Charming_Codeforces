#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = -1e18;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1, delta; i < n; ++i) {
		if (a[i] <= a[i + 1]) {
			delta = a[i] - M;
			a[i] = M, a[i + 1] -= delta;
		}
		else {
			if (i + 1 == n) {
				cout << "NO" << endl;
				return;
			}
			else {
				delta = a[i] - a[i + 1];
				a[i + 2] += delta;
				a[i] = a[i + 1] = M;
				++i;
			}
		}
	}
	cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}