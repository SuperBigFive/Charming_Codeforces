#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, x;
ll POW2[N];

void init () {}

void get () {
	POW2[0] = 1;
	for (int i = 1; i < 64; ++i) {
		POW2[i] = POW2[i - 1] * 2;
	}
}

void charming () {
	init ();
	cin >> n >> x;
	if (n == x) {
		cout << n << endl;
		return;
	}
	ll l = n, r = LLONG_MAX - n, res = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (mid == l) {l += 1; continue;}
		for (int i = 63; i >= 0; --i) {
			if (((n / POW2[i]) & 1) ^ ((mid / POW2[i]) & 1)) {
				if (((n / POW2[i]) * POW2[i]) <= x) r = mid - 1, res = mid;
				else l = mid + 1;
				break;
			}
		}
	}
	for (int i = max (n + 1, res - 2); i <= res + 2; ++i) {
		bool ok = false;
		for (int j = 63; j >= 0; --j) {
			if (((n / POW2[j]) & 1) ^ ((i / POW2[j]) & 1)) {
				if (((n / POW2[j]) * POW2[j]) == x) ok = true;
				break;
			}
		}
		if (ok) {cout << i << endl; return;}
	}
	cout << -1 << endl;
}

signed main () {
	get ();
	cin >> t;
	while (t--) charming ();
	return 0;
}