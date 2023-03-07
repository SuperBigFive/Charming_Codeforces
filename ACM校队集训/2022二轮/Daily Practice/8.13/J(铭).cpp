#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e3 + 5;

int n, m;
int row_m[maxn], col_m[maxn];
int mp[maxn][maxn];

void init () {
	
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mp[i][j];
		}
	}
	int mn;
	for (int i = 1; i <= n; ++i) {
		mn = INT_MAX;
		for (int j = 1; j <= m; ++j) {
			mn = min (mn, mp[i][j]);
		}
		row_m[i] = mn;
	}
	for (int i = 1; i <= m; ++i) {
		mn = INT_MAX;
		for (int j = 1; j <= n; ++j) {
			mn = min (mn, mp[j][i]);
		}
		col_m[i] = mn;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mp[i][j] == row_m[i] && mp[i][j] == col_m[j])
			++res;
		}
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}