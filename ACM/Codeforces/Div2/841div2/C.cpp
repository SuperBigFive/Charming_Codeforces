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
	vector <int> a (n + 5), cnt (n * 2 + 5), sum (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
		++cnt[sum[i]];
	}
	ll res = n * (n + 1) / 2;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j * j <= n * 2 + 5; ++j) {
			if ((sum[i - 1] ^ (j * j)) < n * 2 + 5)
			res -= cnt[sum[i - 1] ^ (j * j)];
		}
		--cnt[sum[i]];
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}