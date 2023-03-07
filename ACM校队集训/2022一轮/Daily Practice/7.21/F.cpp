#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define ppii pair <int, pii >
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e2 + 5;

int n;
char mmap[maxn][maxn];
bool vis[maxn][maxn];

void init () {
	
}

bool check (int x, int y) {
	if (mmap[x + 1][y] == '#' && mmap[x + 1][y - 1] == '#'&& mmap[x + 1][y + 1] == '#' && mmap[x + 2][y] == '#'
	&& !vis[x + 1][y] && !vis[x + 1][y - 1] && !vis[x + 1][y + 1] && !vis[x + 2][y]){
		vis[x][y] = true;
		vis[x + 1][y] = true;
		vis[x + 1][y - 1] = true;
		vis[x + 1][y + 1] = true;
		vis[x + 2][y] = true;
		return true;
	}
	return false;
}

void charming () {
	cin >> n;
	char ch;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> ch;
			mmap[i][j] = ch;
		}
	}
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j == 1 || j == n) {
				if (mmap[i][j] == '#' && !vis[i][j]) {
					cout << "NO" << endl;
					return;
				}
			}
			if (mmap[i][j] == '#' && !vis[i][j]) {
				if (!check (i, j)) {
					cout << "NO" << endl;
					return;
				}
			}
		}
		
	}
	for (int i = 1; i <= n; ++i) {
		if (mmap[n - 1][i] == '#' && !vis[n - 1][i]) {
			cout << "NO" << endl;
			return;
		}
		if (mmap[n][i] == '#' && !vis[n][i]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

signed main () {
	charming ();
	return 0;
}