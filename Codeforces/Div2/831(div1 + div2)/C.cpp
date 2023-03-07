#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
int w[maxn];

void init () {
	
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> w[i];
	sort (w + 1, w + 1 + n);
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		if (i > 2) res = max (res, 2 * w[i] - w[i - 1] - w[1]);
		if (i < n - 1) res = max (res, w[i + 1] + w[n] - 2 * w[i]);
	}
	res = max ({res, 2 * w[n] - w[n - 1] - w[1], w[2] - w[1] + w[n] - w[1]});
	cout << max (res, w[n] - w[1]) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}