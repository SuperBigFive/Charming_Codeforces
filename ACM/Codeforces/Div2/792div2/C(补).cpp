#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m, c1, c2, tot;
int i, j, k;
bool flag;
int cnt[2];
vector <int> row[maxn];

void init () {
	tot = 0;
	cnt[0] = cnt[1] = 0;
	for (int i = 1; i <= n; ++i) row[i].clear ();
	flag = false;
}

void check () {
	if (tot == 1) {
		k = cnt[0] - 1;
		while (k && row[i][k-1] == row[i][k]) --k;
		c1 = k;
		k = cnt[0];
		while (k < m - 1 && row[i][k+1] == row[i][k]) ++k;
		c2 = k; 
	}
	else {
		k = cnt[0] - 1;
		while (k && row[i][k-1] == row[i][k]) --k;
		c1 = k;
		k = cnt[1];
		while (k < m - 1 && row[i][k+1] == row[i][k]) ++k;
		c2 = k; 
	}
}

void solve () {
	cin >> n >> m;
	init ();
	int tmp;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			cin >> tmp;
			row[i].push_back (tmp);
		}
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j < m; ++j) {
			if (row[i][j] < row[i][j-1]) {
				if (tot > 1) {
					cout << -1 << endl;
					return;
				}
				cnt[tot++] = j;
			}
		}
		if (tot) {
			check ();
			break;
		}
	}
	if (flag) {
		cout << -1 << endl;
		return;
	}
	if (!tot) cout << 1 << " " << 1 << endl;
	else {
		for (int i = 1; i <= n; ++i) {
			tmp = row[i][c1];
			row[i][c1] = row[i][c2];
			row[i][c2] = tmp;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j < m; ++j) {
				if (row[i][j] < row[i][j-1]) {
					cout << -1 << endl;
					return;
				}
			}
		}
		cout << c1 + 1<< " " << c2 + 1<< endl;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) solve ();
}
