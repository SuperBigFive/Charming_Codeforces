#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, l, r;
int ans[N];

void init () {}

void get () {
	for (int i = 1, mx, mn, j; i < N; ++i) {
		mx = 0, mn = 10, j = i;
		while (j) {
			mx = max (mx, j % 10);
			mn = min (mn, j % 10);
			j /= 10;
		}
		ans[i] = mx - mn;
	}
}

void charming () {
	init ();
	cin >> l >> r;
	int res = l, mx = 0;
	for (int i = l; i <= r && mx < 9; ++i) {
		if (ans[i] > mx) mx = ans[i], res = i;
	}
	cout << res << endl;
}

signed main () {
	get ();
	cin >> t;
	while (t--) charming ();
	return 0;
}