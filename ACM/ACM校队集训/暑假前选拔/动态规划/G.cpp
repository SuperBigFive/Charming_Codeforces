#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2 + 5;
const ll mod = 924844033;

int n, m;
int i, j, p, q;
ll tnc[maxn*maxn];
ll C[maxn][maxn];
ll dp[maxn][maxn];

void init () {
	tnc[0] = 1;
	for (i = 1; i <= 1e4 + 5; ++i) tnc[i] = (tnc[i-1] * 3) % mod;
	for (i = 0; i <= 101; ++i) {
		C[i][0] = 1;
		for (j = 1; j <= i; ++j) {
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
		}
	}
	/*for (i = 0; i <= 10; ++i) {
		for (j = 0; j <= 10; ++j) 
		cout << C[i][j] << " ";
	}
	cout << endl;*/
}

bool check () {
	if (p == i - 1  && q == j) return true;
	return false;
}

void solve () {
	cin >> n >> m;
	init ();
	ll mula, mulb ,mulc, muld;
	for (i = 0; i <= n+1; ++i) {	
		for (j = 0; j <= m+1; ++j) {
			dp[i][j] = tnc[i*j];
			for (p = 0; p <= i - 1; ++p) {
				for (q = 0; q <= j; ++q){
					if (check()) break;
						mula = C[i-1][p];
						mulb = (mula * C[j][q]) % mod;
						mulc = (mulb * tnc[(i-1-p)*(j-q)]) % mod;
						muld = (mulc * dp[p+1][q]) % mod;
						dp[i][j] = (dp[i][j] - muld + mod) % mod;
				}
			}
			dp[i][j] = (dp[i][j] + mod) % mod;
		}
	}
	dp[n][m] = (dp[n][m] + mod) % mod;
	cout << dp[n][m] << endl;
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	solve ();
}
