#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

int t, n, m;
int mmap[100][100];

void charming () {
	cin >> n >> m;
	int mmax = -1e9 - 5, row, col, ans;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mmap[i][j];
			if (mmap[i][j] > mmax) {
				row = i, col = j;
				mmax = mmap[i][j];
				ans = max (row, n - row + 1) * max (col, m - col + 1);
			}
		}
	}
	cout << ans << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0; 
}
