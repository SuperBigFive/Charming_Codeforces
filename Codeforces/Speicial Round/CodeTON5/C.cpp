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
	vector <int> a (n), l (n, INT_MAX), dp (n), last (n, -1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i], --a[i];
		if (last[a[i]] > -1) l[i] = last[a[i]];
		last[a[i]] = i;
	}
	vector <int> ok (n);
	for (int i = 1; i < n; ++i) {
		if (l[i] < INT_MAX) {
			if (dp[l[i]] + i - l[i] + 1 - ok[l[i]] > dp[i - 1]) {
				dp[i] = dp[l[i]] + i - l[i] + 1 - ok[l[i]];
				ok[i] = 1;
			}
			else dp[i] = dp[i - 1];
		}
		else dp[i] = dp[i - 1];
	}
	cout << *max_element (dp.begin (), dp.end ()) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}