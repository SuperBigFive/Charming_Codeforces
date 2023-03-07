#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int p;
int dp1[2][N];
pair <int ,int> dp2[2][N];

void init () {}

void charming () {
	init ();
	cin >> p;
	vector <int> a (N), b;
	for (int i = 0; i < N; ++i) 
	a[i] = i * (i - 1) / 2, dp1[1][i] = INT_MAX;
	dp1[1][0] = 0;
	int q = p;
	int lim = 0;
	while (a[lim + 1] <= p) ++lim;
	for (int i = 2; i <= lim; ++i) {
		for (int j = 0; j <= q; ++j) {
			dp1[i & 1][j] = dp1[(i - 1) & 1][j];
			dp2[i & 1][j] = dp2[(i - 1) & 1][j];
			if (j >= a[i] && dp1[i & 1][j - a[i]] + i < dp1[i & 1][j]) {
				dp1[i & 1][j] = dp1[i & 1][j - a[i]] + i;
				dp2[i & 1][j].first = dp2[i & 1][j - a[i]].first + i;
				dp2[i & 1][j].second = dp2[i & 1][j - a[i]].second + dp2[i & 1][j - a[i]].first * i;
			}
			else if (j >= a[i] && dp1[i & 1][j - a[i]] + i == dp1[i & 1][j]
			&& dp2[i & 1][j - a[i]].second + dp2[i & 1][j - a[i]].first * i > dp2[i & 1][j].second) {
				dp2[i & 1][j].first = dp2[i & 1][j - a[i]].first + i;
				dp2[i & 1][j].second = dp2[i & 1][j - a[i]].second + dp2[i & 1][j - a[i]].first * i;
			}
		}
	}
	cout << dp1[lim & 1][q] << " " << dp2[lim & 1][q].second << endl;
}

signed main () {
	charming ();
	return 0;
}