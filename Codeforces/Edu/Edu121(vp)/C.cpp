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
	vector <int> k (n + 1), h (n + 1);
	for (int i = 1; i <= n; ++i) cin >> k[i];
	for (int i = 1; i <= n; ++i) cin >> h[i];
	vector <int> mn (n + 1);
	mn[n] = h[n];
	for (int i = n - 1; i >= 1; --i) {
		mn[i] = max (h[i], mn[i + 1] - (k[i + 1] - k[i]));
	}
	ll res = mn[1] * (mn[1] + 1) / 2;
	int cur = mn[1];
	for (int i = 2; i <= n; ++i) {
		if (k[i] - k[i - 1] >= mn[i]) {
			cur = mn[i];
			res += mn[i] * (mn[i] + 1) / 2;
		}
		else {
			int nxt = cur + k[i] - k[i - 1];
			res += (cur + 1 + nxt) * (nxt - cur) / 2;
			cur = nxt;
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}