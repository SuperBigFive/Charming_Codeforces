#include <bits/stdc++.h>
#define ll long long
#define int ll
const int maxn = 5e2 + 5;
const int mod = 998244353;

int n, x;
int dp[maxn][maxn];
int POW[maxn][maxn], C[maxn][maxn];

void init () {
	for (int i = 0; i < maxn; ++i)
	std :: fill (dp[i], dp[i] + maxn, -1);
}

void get_pow () {
	for (int i = 1; i < maxn; ++i) {
		POW[i][0] = 1;
		for (int j = 1; j < maxn; ++j) {
			POW[i][j] = (POW[i][j - 1] * i) % mod; 
		}
	}
}
	
void get_c () {
	C[0][0] = 1;
	for (int i = 1; i < maxn; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
		C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
}

int dfs (int n, int x) {
	if (dp[n][x] != -1) return dp[n][x];
	if (x < n) return dp[n][x] = POW[x][n];
	if (n == 2) return dp[n][x] = x;
	dp[n][x] = POW[n - 1][n];
	for (int i = 0; i <= n - 2; ++i) {
		dp[n][x] = (dp[n][x] + 
		((dfs (n - i, x - (n - 1)) * C[n][i]) % mod)
		 * POW[n - 1][i]) % mod;
	}
	return dp[n][x];
}

void charming () {
	init ();
	int n, x;
	std :: cin >> n >> x;
	std :: cout << dfs (n, x) << std :: endl;
}

signed main () {
	get_pow (), get_c ();
	charming ();
	return 0;
}