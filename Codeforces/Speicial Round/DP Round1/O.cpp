#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e2 + 5;
const int M = 1e4 + 5;

int n; 

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <pair <int, int> > a (n + 1);
	vector <vector <vector <int> > > dp (2, 
	vector <vector <int> > (N, vector <int> (M, -1)));
	double c = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;	
		c += (double) a[i].second / 2;
	}
	dp[0][0][0] = dp[1][0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		auto [v, cur] = a[i];
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < M - v; ++k) {
				if (k < v) dp[i & 1][j + 1][k] = dp[(i - 1) & 1][j + 1][k];
				dp[i & 1][j + 1][k + v] = max (dp[i & 1][j + 1][k + v],
				dp[(i - 1) & 1][j + 1][k + v]);
				if (dp[(i - 1) & 1][j][k] != -1) {
					dp[i & 1][j + 1][k + v] = max (dp[i & 1][j + 1][k + v],
					dp[(i - 1) & 1][j][k] + cur);
				}
			}
		}
		for (int j = 0; j < N; ++j)
		for (int k = 0; k < M; ++k)
		dp[(i + 1) & 1][j][k] = -1;
		dp[i & 1][0][0] = 0;
	}
	for (int j = 1; j <= n; ++j) {
		double res = 0;
		for (int k = 0; k < M; ++k) {
			if (dp[n & 1][j][k] != -1)
			res = max (res, min ((double) c + (double) dp[n & 1][j][k] / 2, (double) k));
		}
		cout << setprecision (13) << res << " \n"[j == n]; 
	}
}

signed main () {
	charming ();
	return 0;
}