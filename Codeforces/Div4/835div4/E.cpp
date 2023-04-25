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
	vector <int> a (n + 1), sum0 (n + 1), sum1 (n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum0[i] = sum0[i - 1];
		sum1[i] = sum1[i - 1];
		if (!a[i]) ++sum0[i];
		else ++sum1[i];
	}
	ll res = 0, mx = 0;
	for (int i = 1; i <= n; ++i) {
		if (!a[i]) {
			mx = max (mx, (sum0[n] - sum0[i]) - sum1[i]);
		}
		else {
			res += sum0[n] - sum0[i];
			mx = max (mx, sum1[i - 1] - (sum0[n] - sum0[i]));
		}
	}
	cout << res + mx << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}