#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e9 + 5;

int t, n;

void init () {}

ll qsm (int num, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = res * num;
		p >>= 1;
		num = num * num;
		if (num > N || res > N) return N;
	}
	return res;
}

void charming () {
	init ();
	cin >> n;
	if (!(n & 1)) return void (cout << 1 << " " << n / 2 << endl);
	int mx = sqrt (n);
	for (int i = 2; i <= 10; ++i) {
		ll a = 1, b;
		for (int j = 1; j <= n; ++j) {
			a *= i, b = qsm (j, i);
			if (a * j + b * i > n) break;
			if (a * j + b * i == n) {
				cout << i << " " << j << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}