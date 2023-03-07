#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

ll get (ll num) {return n * num - num * num;}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort (a.begin () + 1, a.end ());
	ll res = n / 2;
	for (int i = 1, j; i <= n; i = j + 1) {
		j = i;
		while (j + 1 <= n && a[j + 1] == a[i]) ++j;
		res = max (res, (j - i + 1) * (n - j) + (n - j) * (i - 1));
		res = max (res, (j - i + 1) / 2 + (n - j) * (i - 1));
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}