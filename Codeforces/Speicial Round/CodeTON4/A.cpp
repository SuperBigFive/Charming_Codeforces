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
	bool ok = false;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] <= i) ok = true;
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}