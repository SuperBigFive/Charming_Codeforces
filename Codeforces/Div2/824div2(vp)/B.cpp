#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, mn;
int a[maxn];

void init () {
	mn = INT_MAX;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) 
	cin >> a[i], mn = min (mn, a[i]);
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] >= 2 * mn) {
			res += (a[i] - 1) / (2 * mn - 1);
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}