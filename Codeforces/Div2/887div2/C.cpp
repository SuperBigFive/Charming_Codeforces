#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (a[1] != 1) return void (cout << 1 << endl);
	int small = 1, step = 1, p = 2;
	for (int i = 1; i <= k; ++i) {
		while (p <= n && small + step >= a[p]) ++step, ++p;
		if (p > n) return void (cout << small + n * (k - i + 1) << endl);
		small += step;
	}
	cout << small << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}