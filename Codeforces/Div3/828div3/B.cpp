#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, q;

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	vector <int> a (n + 5);
	int sum_odd = 0, sum_even = 0;
	int cnt_odd = 0, cnt_even = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] & 1) sum_odd += a[i], ++cnt_odd;
		else sum_even += a[i], ++cnt_even;
	}
	int opt, x;
	for (int i = 1; i <= q; ++i) {
		cin >> opt >> x;
		if (opt == 0) {
			if (x & 1) {
				sum_odd += sum_even + x * cnt_even;
				cnt_odd += cnt_even;
				sum_even = cnt_even = 0;
			}
			else {
				sum_even += x * cnt_even;
			}
		}
		else {
			if (!(x & 1)) {
				sum_odd += x * cnt_odd;
			}
			else {
				sum_even += sum_odd + x * cnt_odd;
				cnt_even += cnt_odd;
				sum_odd = cnt_odd = 0;
			}
		}
		cout << sum_even + sum_odd << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}