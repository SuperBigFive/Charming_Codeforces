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
	int cnt = 0;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] % k != i % k) ++cnt;
	}
	if (cnt == 0) cout << 0 << endl;
	else if (cnt == 2) cout << 1 << endl;
	else cout << -1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}