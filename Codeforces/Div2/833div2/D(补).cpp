#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t;
ll a, b, d, x;
ll POW2[65];

void init () {}

void get_POW2 () {
	POW2[0] = 1;
	for (int i = 1; i <= 30; ++i) POW2[i] = POW2[i - 1] * 2;
}

void charming () {
	init ();
	cin >> a >> b >> d;
	ll la = a & -a, lb = b & -b, ld = d & -d;
	if (ld > la || ld > lb) {
		cout << -1 << endl;
		return;
	}
	x = d;
	for (int i = 1; i <= 30; ++i) {
		if (POW2[i] < ld) continue;
		if (((x / POW2[i - 1]) & 1) == 0) x += d * (POW2[i - 1] / ld);
	}
	cout << x << endl;
}

signed main () {
	get_POW2 ();
	cin >> t;
	while (t--) charming ();
	return 0;
}