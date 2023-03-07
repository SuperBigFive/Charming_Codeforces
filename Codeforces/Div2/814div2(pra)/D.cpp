#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 3e5 + 5;

int t, n;
int val[maxn], dp[maxn];

void init () {
	for (int i = 0; i <= n + 1; ++i) dp[i] = 0;
}

void charming () {
	init ();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> val[i];
	}
	dp[0] = dp[1] = 1;
	
	for (int i = 0, lim; i < n; ++i) {
		dp[i] = 1;
		lim = max (0ll, i - 256);
		for (int j = i - 1; j >= lim; --j) {
			if ((val[j] ^ i) < (val[i] ^ j)) dp[i] = max (dp[i], dp[j] + 1);
		}
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res = max (res, dp[i]);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}