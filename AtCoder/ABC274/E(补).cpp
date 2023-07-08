#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 20;
const int maxm = 2e6 + 5;

int n, m;
double x[maxn], y[maxn];
double dp[maxn][maxm];

void init () {
	for (int i = 0; i < maxn; ++i) 
	fill (dp[i], dp[i] + maxm, LLONG_MAX);
}

bool bit (int s, int i) {return (s >> i) & 1;}

void charming () {
	init ();
	scanf ("%lld%lld", &n, &m);
	for (int i = 0; i < n + m; ++i) {
		scanf ("%lf%lf", &x[i], &y[i]);
	}
	for (int i = 0; i < n + m; ++i) 
	dp[i][1 << i] = hypot (x[i], y[i]);
	for (int s = 1; s < (1 << n + m); ++s) {
		double coef = pow (0.5, __builtin_popcount (s >> n));
		for (int i = 0; i < n + m; ++i) if (bit (s, i)) {
			for (int j = 0; j < n + m; ++j) if (!bit (s, j)) {
				dp[j][s ^ (1 << j)] = fmin (dp[j][s ^ (1 << j)], 
				dp[i][s] + hypot (x[i] - x[j], y[i] - y[j]) * coef);
			}
		}
	}
	double res = LLONG_MAX;
	for (int i = 0; i < n + m; ++i) {
		for (int s = (1 << n) - 1; s < (1 << n + m); s += (1 << n)) {
			double coef = pow (0.5, __builtin_popcount (s >> n));
			res = fmin (res, dp[i][s] + hypot (x[i], y[i]) * coef);
		}
	}
	printf ("%.10lf\n", res);
}

signed main () {
	charming ();
	return 0;
}