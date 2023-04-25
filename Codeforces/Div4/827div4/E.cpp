#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, q;
int a[maxn], sum[maxn], mx[maxn];

void init () {
	for (int i = 1; i <= n; ++i)
	sum[i] = mx[i] = 0;
}

void charming () {
	init ();
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		mx[i] = max (mx[i - 1], a[i]);
	}
	for (int i = 1, k; i <= q; ++i) {
		cin >> k;
		int id = upper_bound (mx + 1, mx + 1 + n, k) - mx - 1;
		if (id <= 0) cout << 0 << " ";
		else cout << sum[id] << " ";
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}