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
	vector <int> a (n << 2), b (n << 2), ansa (n << 2), ansb (n << 2);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	for (int i = 1, j; i <= n; i = j + 1) {
		j = i;
		while (j + 1 <= n && a[j + 1] == a[j]) ++j;
		ansa[a[i]] = max (ansa[a[i]], j - i + 1);
	}
	for (int i = 1, j; i <= n; i = j + 1) {
		j = i;
		while (j + 1 <= n && b[j + 1] == b[j]) ++j;
		ansb[b[i]] = max (ansb[b[i]], j - i + 1);
	}
	int ans = 0;
	for (int i = 1; i <= n * 2; ++i) ans = max (ans, ansa[i] + ansb[i]);
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}