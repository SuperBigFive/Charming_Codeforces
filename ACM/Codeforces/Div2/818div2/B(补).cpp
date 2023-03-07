#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1505;

int t, n, k, r, c;
char mp[maxn][maxn];

void init () {
	for (int i = 0; i < maxn; ++i) {
		for (int j = 0; j < maxn; ++j) mp[i][j] = '.';
	}
}

void add_x (int x, int y) {
	for (int tmp_y = y; tmp_y > 500; tmp_y -= k) {
		mp[x][tmp_y] = 'X';
	}
	for (int tmp_y = y; tmp_y <= 500 + n; tmp_y += k) {
		mp[x][tmp_y] = 'X';
	}
}

void charming () {
	init ();
	cin >> n >> k >> r >> c;
	r += 500, c += 500;
	mp[r][c] = 'X';
	for (int i = 500; i <= 500 + n; ++i) {
		mp[i][i + c - r] = 'X';
		add_x (i, i + c - r); 
	}
	for (int i = 500 + 1; i <= 500 + n; ++i) {
		for (int j = 500 + 1; j <= 500 + n; ++j) {
			cout << mp[i][j];
		}
		cout << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}