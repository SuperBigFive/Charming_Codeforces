#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	int sum = 0;
	vector <int> a (n);
	for (auto &it : a) cin >> it, sum += it;
	sort (a.begin (), a.end ());
	vector <int> pre (n + 5), suf (n + 5);
	pre[0] = a[0], suf[n - 1] = a[n - 1];
	for (int i = 1; i < n; ++i) {
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = n - 2; i >= 0; --i) {
		suf[i] = suf[i + 1] + a[i];
	}
	int ans = sum - suf[n - k];
	for (int i = 1; i <= k; ++i) ans = max (ans, sum - pre[i * 2 - 1] - suf[n - (k - i)]);
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}