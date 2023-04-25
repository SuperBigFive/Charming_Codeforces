#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e5 + 5;

int t, n, k;
ll arr[maxn], mx[maxn];

void init () {
	fill (mx, mx + maxn, 0);
}

void charming () {
	init ();	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		mx[i % k] = max (mx[i % k], arr[i]);
	}
	ll res = 0;
	for (int i = 0; i < k; ++i) {
		res += mx[i];
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}