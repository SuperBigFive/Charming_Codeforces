#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e3 + 5;

int t, n, m;
int mmap[maxn][maxn];
int mmax[maxn][maxn], mmin[maxn][maxn];

void init () {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) 
		mmax[i][j] = mmin[i][j] = 0;
	}
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mmap[i][j];
		}
	}
	for (int i = 1; i <= m; ++i) {
		mmax[1][i] = mmax[1][i-1] + mmap[1][i];
		mmin[1][i] = mmax[1][i];
	}
	for (int i = 1; i <= n; ++i) {
		mmin[i][1] = mmin[i-1][1] + mmap[i][1];
		mmax[i][1] = mmin[i][1];
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= m; ++j) {
			mmax[i][j] = max (mmax[i-1][j], mmax[i][j-1]) + mmap[i][j];
			mmin[i][j] = min (mmin[i-1][j], mmin[i][j-1]) + mmap[i][j];
		}
	}
	if ((n + m - 1) & 1) cout << "NO" << endl;
	else if (mmax[n][m] >= 0 && mmin[n][m] <= 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}
