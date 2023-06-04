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
	int p1 = 0, p2 = 0, pn = 0;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == 1) p1 = i;
		else if (a[i] == 2) p2 = i;
		else if (a[i] == n) pn = i;
	}
	if (p1 < p2) {
		if (pn < p1) cout << pn << " " << p1 << endl;
		else if (pn < p2) cout << 1 << " " << 1 << endl;
		else cout << pn << " " << p2 << endl;
	} else {
		if (pn > p1) cout << pn << " " << p1 << endl;
		else if (pn > p2) cout << 1 << " " << 1 << endl;
		else cout << pn << " " << p2 << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}