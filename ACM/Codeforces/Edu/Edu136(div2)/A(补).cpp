#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void init () {}

bool check (int x, int y) {
	int new_x, new_y;
	for (int i = 0; i < 8; ++i) {
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (new_x >= 1 && new_x <= n 
		&& new_y >= 1 && new_y <= m) return false;
	}
	return true;
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (check (i, j)) {
				cout << i << " " << j << endl;
				return;
			}
		}
	}
	cout << 1 << " " << 1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}