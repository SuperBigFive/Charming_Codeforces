#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e2 + 5;

int D, K;
int d[25];
int dp[1 << 16][maxn];

void init () {}

void charming () {
	cin >> D >> K;
	for (int i = 0; i < D; ++i) cin >> d[i];	
	memset (dp, -1, sizeof dp);
	dp[0][0] = 0;
	for (int s = 0; s < (1 << D); ++s) {
		for (int i = 0; i < D; ++i) {
			if ((s >> i) & 1) continue;
			for (int j = 0, nxt; j < K; ++j) {
				if (dp[s][j] == -1) continue;
				nxt = (j * 10 + d[i]) % K;
				dp[s | (1 << i)][nxt] = max (dp[s | (1 << i)][nxt],
				dp[s][j] * 10 + d[i]);
			}
		}
	}
	for (int i = K - 1; i >= 0; --i) {
		if (dp[(1 << D) - 1][i] != -1) {
			cout << dp[(1 << D) - 1][i] << endl;
			break;
		}
	}
}

signed main () {
	charming ();
	return 0;	
}