#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e3 + 5;

int n;
int h[maxn];
int see[maxn][maxn];
int dp[maxn][maxn];

void init () {
	for (int i = 1; i < maxn; ++i)
	for (int j = i; j < maxn; ++j)
	dp[i][j] = 0;
}

void get_see () {
	for (int i = 1, id; i < n; ++i) {
		see[i][i] = see[i][i + 1] = 1;
		id = i + 1;
		for (int j = i + 2; j <= n; ++j) {
			if ((h[j] - h[i]) * (id - i) > (h[id] - h[i]) * (j - i)) {
				see[i][j] = 1;
				id = j;
			}
		}
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	get_see ();
	for (int i = 1, id, last, sum; i <= n; ++i) {
		id = i;
		last = sum = 0;
		dp[i][i] = 1;
		for (int j = i - 1; j >= 1; --j) {
			if (see[j][i]) {
				sum += last;
				id = j;
			}
			last = min (dp[j][id], dp[j][id - 1]);
			dp[j][i] = sum + last + 1;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = i; j <= n; ++j)
	res ^= dp[i][j];
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}