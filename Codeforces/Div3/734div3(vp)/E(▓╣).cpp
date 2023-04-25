#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e3 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <int> a (n + 5);
	vector <pair <int, int> > dp (n + 5, make_pair (0, INT_MAX));
	for (int i = 1; i <= n; ++i) cin >> a[i];	
	int res = INT_MAX;
	dp[0] = make_pair (0, 0);
	for (int i = 1; i <= n; ++i) {
		if (i - a[i] < 0) continue;
		dp[i].second = i - a[i];
		for (int j = 0; j < i; ++j) {
			if (dp[j].second > i - a[i] || a[j] >= a[i]) continue;
			dp[i].first = max (dp[i].first, dp[j].first + 1); 
		}
		if (dp[i].first >= k) res = min (res, dp[i].second);
	}
	if (res >= INT_MAX) cout << -1 << endl;
	else cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}