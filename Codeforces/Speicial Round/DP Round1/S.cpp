#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 70 + 5;

int n, m, k;
int dp1[N][N][N], dp2[N][N];

void init () {}

void charming () {
	init ();
	cin >> n >> m >> k;
	vector <vector <int> > a (n + 5, vector <int> (m + 5));
	vector <vector <int> > mx (n + 5, vector <int> (k + 5));
	for (int i = 0; i < n; ++i) {
		memset (dp1, -1, sizeof dp1);
		dp1[0][0][0] = 0;
		for (int j = 0; j < m; ++j) {
			cin >> a[i + 1][j + 1];
			for (int p = 0; p <= m / 2; ++p) {
				for (int q = 0, nxt; q < k; ++q) {
					if (dp1[j][p][q] <= -1) continue;
					dp1[j + 1][p][q] = max (dp1[j + 1][p][q], dp1[j][p][q]);
					nxt = (q + a[i + 1][j + 1]) % k;
					dp1[j + 1][p + 1][nxt] = max (dp1[j + 1][p + 1][nxt], 
					dp1[j][p][q] + a[i + 1][j + 1]);
				}
			}
		}
		for (int j = 0; j <= m / 2; ++j) 
		for (int p = 0; p < k; ++p)
		mx[i + 1][p] = max (mx[i + 1][p], dp1[m][j][p]);
	}
	memset (dp2, -1, sizeof dp2);
	dp2[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			if (dp2[i][j] <= -1) continue;
			for (int p = 0, nxt; p < k; ++p) {
				dp2[i + 1][j] = max (dp2[i + 1][j], dp2[i][j]);
				if (mx[i + 1][p] <= 0) continue;
				nxt = (j + p) % k;
				dp2[i + 1][nxt] = max (dp2[i + 1][nxt], dp2[i][j] + mx[i + 1][p]);
			}
		}
	}
	cout << dp2[n][0] << endl;
}

signed main () {
	charming ();
	return 0;
}