#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e2 + 5;

int n;
int arr[maxn];
int dp[maxn][maxn];

void init () {}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	dp[2][0] = (arr[2] - arr[1]) * (arr[2] - arr[1]);
	for (int i = 3; i <= n; ++i) {
		dp[i][i - 2] = (arr[i] - arr[1]) * (arr[i] - arr[1]);
		for (int j = 0; j < i - 1; ++j) {
			for (int k = i - j - 1; k < i; ++k) {
				dp[i][j] = max (dp[i][j], dp[k][j - i + k + 1] 
				+ (arr[i] - arr[k]) * (arr[i] - arr[k]));
			}
		}
	}
	for (int i = 1; i <= n; ++i) 
	cout << dp[n][min (i * 2, n - 2)] << endl;
}

signed main () {
	charming ();
	return 0;
}