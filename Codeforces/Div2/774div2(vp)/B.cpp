#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort (a.begin () + 1, a.end ());
	ll R = 0, B = a[1];
	int p1 = 2, p2 = n;
	while (p1 <= p2 + 1) {
		if (R > B) {
			cout << "YES" << endl;
			return;
		}
		R += a[p2--];
		B += a[p1++];
	}
	cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}