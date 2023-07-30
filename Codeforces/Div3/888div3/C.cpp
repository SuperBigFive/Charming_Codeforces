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
	vector <int> a (n + 5);
	vector <int> pos1, posn;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		if (a[i] == a[1]) pos1.emplace_back (i);
	}
	for (int i = n; i >= 1; --i) {
		if (a[i] == a[n]) posn.emplace_back (i);
	}
	if ((int) pos1.size () < k || (int) posn.size () < k) cout << "No" << endl;
	else if (pos1[k - 1] > posn[k - 1] && a[1] != a[n]) cout << "No" << endl;
	else cout << "Yes" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}