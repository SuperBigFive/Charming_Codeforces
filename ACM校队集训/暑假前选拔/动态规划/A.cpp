#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;

int n, m, x, y, z;
int mmax;
int i, j, k;
int dp[maxn][maxn];
char A[maxn],B[maxn];

void init () {
	mmax = -1;
	for (i = 0; i <= n; ++i) {
		dp[i][0] = 0;
	}
	for (i = 0; i <= m; ++i) {
		dp[0][i] = 0;
	}
}

void check () {}

void solve () {
	cin >> A + 1 >> B + 1;
	init ();
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			if (A[i] == B[j]) {
				dp[i][j] = max (dp[i-1][j-1] + x - y - z, dp[i-1][j] - y);
				dp[i][j] = max (dp[i][j], dp[i][j-1] - z);
				dp[i][j] = max (dp[i][j], x - y - z);
			}
			else {
				dp[i][j] = max (dp[i-1][j] - y, dp[i][j-1] - z);
				dp[i][j] = max (dp[i][j], - y - z);
			}
			mmax = max (mmax, dp[i][j]);
		}
	}
	if (mmax < 0) cout << 0 << endl;
	else cout << mmax << endl;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> x >> y >> z;
	solve ();
}
