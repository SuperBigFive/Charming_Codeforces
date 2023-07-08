#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	bool ok = true;
	int now, nxt, last;
	for (int i = 1, tmp; i <= k; ++i) {
		cin >> nxt;
		if (i == 1) {
			if (nxt == 0) tmp = 0;
			else if (nxt > 0) tmp = (nxt - 1) / (n - k + 1) + 1;
			else tmp = nxt / (n - k + 1);
			now = nxt;
			continue;
		}
		if (i == 2) {
			last = nxt - now;
			if (last < tmp) ok = false;
			now = nxt;
			continue;
		}
		if (nxt - now < last) ok = false;
		last = nxt - now;
		now = nxt;
	}
	cout << (ok ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}