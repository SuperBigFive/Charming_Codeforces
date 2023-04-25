#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, x;

void init () {}

void charming () {
	init ();
	cin >> n >> x;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int mn = 30;
	vector <bool> ok (35);
	for (int i = 30, notSame; i >= 0; --i) {
		notSame = false;
		for (int j = 1; j <= n; ++j)
		notSame |= ((a[j] >> i) & 1) != ((a[1] >> i) & 1);
		if (notSame) {
			ok[i] = true, mn = i;
			if (((x >> i) & 1) == 0) return void (cout << x << endl);
		}
	}
	cout << x - (1 << mn) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}