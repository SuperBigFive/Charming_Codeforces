#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	if (n == 1) return void (cout << "YES" << endl);
	else if (n <= m) return void (cout << "NO" << endl);
	int l = 1, r = m, k = 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (mid == m) {k = mid; break;}
		else if (n / mid >= ((n % mid) + (m - mid) - 1) / (m - mid)) l = mid + 1, k = mid;
		else r = mid - 1;
	}
	int fiPrime = -1;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {fiPrime = i; break;}
	}
	if (fiPrime == -1) fiPrime = n;
	if (fiPrime <= k) cout << "NO" << endl;
	else cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}