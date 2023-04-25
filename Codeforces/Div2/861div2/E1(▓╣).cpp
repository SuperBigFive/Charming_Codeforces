#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 105;
const int K = 35;

int n, k, m;

void init () {}

void charming () {
	init ();
	cin >> n >> k >> m;	
	vector <set <int> > ok (k + 5);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			if ((j * 2) % k != i) ok[i].insert (j);
		}
	}
	ll ans = 1;
	for (int i = 1; i <= n; ++i) ans = (ans * k) % m;
	for (int sum = 0; sum < k; ++sum) {
		vector <vector <int> > dp (n + 5, vector <int> (k + 5));
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (auto j : ok[sum]) {
				for (int p = 0, nsum; p < k; ++p) {
					nsum = (j + p) % k;
					dp[i][nsum] = (dp[i][nsum] + dp[i - 1][p]) % m;
				}
			}
		}
		ans = (ans - dp[n][sum]) % m;
	}
	ans = ((ans % m) + m) % m;
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}