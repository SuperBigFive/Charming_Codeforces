#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, c;

void init () {}

void charming () {
	init ();
	cin >> n >> c;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += i;
	sort (a.begin () + 1, a.begin () + 1 + n);
	int res = 0;
	for (int i = 1; i <= n; ++i)
	if (c >= a[i]) ++res, c -= a[i];
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}