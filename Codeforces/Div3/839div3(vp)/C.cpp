#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> k >> n;
	vector <int> a (k + 1);
	a[1] = 1;
	for (int i = 2, cur = 1; i <= k; ++i) {
		if (a[i - 1] + cur + k - i <= n) {
			a[i] = a[i - 1] + cur;
			++cur;
		}
		else {
			a[i] = a[i - 1] + 1;
			cur = 1;
		}
	}
	for (int i = 1; i <= k; ++i) {
		cout << a[i] << " \n"[i == k];
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}