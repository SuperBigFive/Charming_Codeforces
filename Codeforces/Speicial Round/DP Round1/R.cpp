#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 4e2 + 5;
const int K = 2e2 + 5;

int n, k;
int dp1[N][N], dp2[N][K];

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort (a.begin () + 1, a.begin () + 1 + n);
	for (int len = 2; len <= n; len ++) {
		for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
			if (len & 1) dp1[i][j] = dp1[i - 1][j];
			else dp1[i][j] = max ({dp1[i + 1][j - 1] + a[j] - a[i],
			dp1[i][j - 2] + a[j] - a[j - 1], dp1[i + 2][j] + a[i + 1] - a[i]});
		}
	}
	memset (dp2, -1, sizeof dp2);
	dp2[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp2[i][0] = 0;
		for (int j = 1; j <= k; ++j) {
			for (int p = i; p >= 1; --p) {
				if ((i - p + 1) / 2 > j) break;
				if (dp2[p - 1][j - (i - p + 1) / 2] > -1)
				dp2[i][j] = max (dp2[i][j], dp1[p][i] + dp2[p - 1][j - (i - p + 1) / 2]);
			}
		}
	}
	cout << dp2[n][k] << endl;
}

signed main () {
	charming ();
	return 0;
}