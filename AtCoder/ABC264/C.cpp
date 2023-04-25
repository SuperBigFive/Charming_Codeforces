#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int h1, h2, w1, w2;
int mp_a[20][20], mp_b[20][20];
int tmp_a[20][20];
bool vis[20][20];

void init () {
	
}

bool check (int st_r, int st_c) {
	memset (vis, 0, sizeof vis);
	int tot_r = h1, tot_c = w1;
	for (int i = 1; i <= h1; ++i) {
		if (st_r & (1 << (i - 1))) {
			for (int j = 1; j <= w1; ++j) {
				vis[i][j] = true;
			}
			--tot_r;
		}
	}
	for (int i = 1; i <= w1; ++i) {
		if (st_c & (1 << (i - 1))) {
			for (int j = 1; j <= h1; ++j) {
				vis[j][i] = true;
			}
			--tot_c;
		}
	}
	if (tot_r != h2 || tot_c != w2) return false;
	tot_r = 0;
	for (int i = 1; i <= h1; ++i) {
		tot_c = 0;
		for (int j = 1; j <= w1; ++j) {
			if (!vis[i][j]) tmp_a[tot_c ? tot_r : ++tot_r][++tot_c] = mp_a[i][j];
		}
	}
	for (int i = 1; i <= h2; ++i) {
		for (int j = 1; j <= w2; ++j) {
			if (tmp_a[i][j] != mp_b[i][j]) return false;
		}
	}
	return true;
}

void charming () {
	cin >> h1 >> w1;
	for (int i = 1; i <= h1; ++i) 
	for (int j = 1; j <= w1; ++j)
	cin >> mp_a[i][j];
	cin >> h2 >> w2;
	for (int i = 1; i <= h2; ++i)
	for (int j = 1; j <= w2; ++j)
	cin >> mp_b[i][j];
	for (int i = 0; i < (1 << h1); ++i) {
		for (int j = 0; j < (1 << w1); ++j) {
			if (check (i, j)) {
				cout << "Yes" << endl;
				return;
			}
		}
	}
	cout << "No" << endl;
	return;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}