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
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int mn = INT_MAX, delta;
	for (int i = 1; i < n; ++i) {
		delta = a[i + 1] - a[i];
		mn = min (mn, delta);
	}
	if (mn < 0) cout << 0 << endl;
	else cout << (mn) / 2 + 1 << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}