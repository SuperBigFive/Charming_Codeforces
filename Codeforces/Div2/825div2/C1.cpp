#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, q;
int a[maxn], en[maxn];

void init () {
	for (int i = 1; i <= n; ++i) en[i] = 0;
}

void charming () {
	init ();
	cin >> n;
	int r = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		while (a[r] >= r - i + 1 && r <= n) ++r;
		en[i] = r - 1;
	}
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		res += en[i] - i + 1;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}