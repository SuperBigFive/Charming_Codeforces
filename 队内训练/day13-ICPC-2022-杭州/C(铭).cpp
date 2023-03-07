#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 3e3 + 5;

int n, k;
int p[N];
int dp1[N][N], dp2[N][N];
vector <vector <int> > w;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	w.resize (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		vector <int> wi (p[i] + 5);
		for (int j = 1; j <= p[i]; ++j) {
			cin >> wi[j];
		}
		w[i] = wi;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < N; ++j) {
			dp1[i][j] = dp1[i - 1][j];
			if (j >= p[i]) dp1[i][j] = max (dp1[i][j], dp1[i - 1][j - p[i]] + w[i][p[i]]);	
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < N; ++j) {
			dp2[i][j] = dp2[i + 1][j];
			if (j >= p[i]) dp2[i][j] = max (dp2[i][j], dp2[i + 1][j - p[i]] + w[i][p[i]]);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= min (p[i], k); ++j) {
			if (j > k) continue;
			for (int p = 0; p <= k - j; ++p) {
				if ((dp1[i - 1][p] || p == 0) && (dp2[i + 1][k - j - p] || k - j - p == 0))
				res = max (res, w[i][j] + dp1[i - 1][p] + dp2[i + 1][k - j - p]);
			}
		}
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}