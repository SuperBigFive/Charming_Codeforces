#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int val[maxn];

void init () {}

void charming () {
	cin >> n;
	int mx = -1, mn = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		if (val[i] >= mx && i > 1) {
			mx = val[i];
		}
		if (val[i] <= mn && i < n) {
			mn = val[i];
		}
	}
	int ans = val[n] - val[1];
	for (int i = 1; i < n; ++i) {
		ans = max (ans, val[i] - val[i + 1]);
	}
	ans = max ({ans, mx - val[1], val[n] - mn});
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}