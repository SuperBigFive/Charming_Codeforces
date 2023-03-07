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
	vector <int> fac (n + 1), num (n + 1);
	for (int i = 1; i <= n; ++i) {
		fac[i] = n / i;
	}
	for (int i = n; i >= 1; --i) {
		num[i] = (fac[i] - 1) * fac[i] / 2;
		for (int j = i + i; j <= n; j += i)
		num[i] -= num[j];
	}
	ll res = m;
	int remain = m;
	for (int i = min (n, m + 1); i > 1; --i) {
		int d = min (num[i], remain) / (i - 1);
		res += d;
		remain -= (i - 1) * d;
		num[i] -= (i - 1) * d;
	}
	if (remain > 0) cout << -1 << endl;
	else cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}