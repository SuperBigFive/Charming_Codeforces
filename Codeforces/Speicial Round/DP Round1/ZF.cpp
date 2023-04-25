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
	vector <int> a (n + 5), b, c (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	b = a;
	multiset <int> set1, set2;
	for (int i = 0; i < n; ++i) {
		b[i + 1] -= b[i];
		b[i] = 0;
		if ((i + 1) & 1) set1.insert (b[i + 1]);
		else set2.insert (b[i + 1]);
		c[i + 1] = b[i + 1];
	}
	if (b[n] == 0 && *set1.begin () >= 0 
	&& *set2.begin () >= 0) return void (cout << "YES" << endl);
	for (int i = 1; i < n; ++i) {
		int delta = 2 * (a[i + 1] - a[i]);
		if (i & 1) {
			auto it = set1.find (c[i]);
			set1.erase (it);
			if (c[i] + delta / 2 >= 0 && *set1.begin () + delta >= 0 && *set2.begin () - delta >= 0 
			&& b[n] + (n & 1 ? 1 : -1) * delta == 0) return void (cout << "YES" << endl);
		}
		else {
			auto it = set2.find (c[i]);
			set2.erase (it);
			if (c[i] + delta / 2 >= 0 && *set2.begin () + delta >= 0 && *set1.begin () - delta >= 0
			&& b[n] + (n & 1 ? -1 : 1) * delta == 0) return void (cout << "YES" << endl);
		}
		if (c[i] < 0) return void (cout << "NO" << endl);
	}
	cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}