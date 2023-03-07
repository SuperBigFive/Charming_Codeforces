#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 11;
const int maxm = 1e6 + 5;

int n;
int mmap[maxn][maxn];
int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
ll ans[maxm][maxn];
ll res[maxm];

void charming () {
	cin >> n;
	int mmax = -1;
	char ch;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> ch;
			mmap[i][j] = ch - '0';
			mmax = max (mmax, mmap[i][j]);
		}
	}
	vector <int> vx, vy;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (mmap[i][j] == mmax) 
				vx.push_back (i), vy.push_back (j);
		} 
	}
	int tot = 0;
	for (int i = 0; i < vx.size (); ++i) {
		int x = vx[i], y = vy[i];
		for (int j = 0; j < 8; ++j) {
			int dx = dir[j][0], dy = dir[j][1];
			x = vx[i], y = vy[i];
			ans[++tot][1] = mmap[x][y];
			for (int k = 2; k <= n; ++k) {
				x = x + dx, y = y + dy;
				if (x == n + 1) x = 1;
				if (x == 0) x = n;
				if (y == n + 1) y = 1;
				if (y == 0) y = n;
				//x = x % n + dx, y = y % n + dy;
				ans[tot][k] = mmap[x][y];
			} 
		}
	}
	for (int i = 1; i <= tot; ++i) {
		for (int j = 1; j <= n; ++j) {
			res[i] += ans[i][j] * pow (10, n - j);
		}
	}
	sort (res + 1, res + 1 + tot);
	cout << res[tot] << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
