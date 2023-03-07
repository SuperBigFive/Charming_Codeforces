#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e3 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5), b;
	vector <vector <int> > dp (n + 5, vector <int> (n + 5, INT_MAX));	
	for (int i = 1; i <= n; ++i) cin >> a[i]; b = a;
	sort (b.begin () + 1, b.begin () + 1 + n);
	int len = unique (b.begin () + 1, b.begin () + 1 + n) - b.begin () - 1;
	for (int i = 1; i <= n; ++i)
	a[i] = lower_bound (b.begin () + 1, b.begin () + 1 + len, a[i]) - b.begin ();
	bool zero = (b[1] == 0);
	dp[0][zero] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = zero; j <= n; ++j) {
			if (dp[i][j] >= INT_MAX) continue;
			if (j <= a[i + 1]) dp[i + 1][j] = min (dp[i + 1][j], dp[i][j] + 1);
			else dp[i + 1][a[i + 1]] = min (dp[i + 1][a[i + 1]], dp[i][j] + 1);
			if (j >= a[i + 1]) dp[i + 1][a[i + 1]] = min (dp[i + 1][a[i + 1]], dp[i][j]);
			else dp[i + 1][a[i + 1]] = min (dp[i + 1][a[i + 1]], dp[i][j] + b[a[i + 1]] - b[j]);
		}
	}
	int res = INT_MAX;
	for (int i = 0; i <= n; ++i)
	res = min (res, dp[n][i]);
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}