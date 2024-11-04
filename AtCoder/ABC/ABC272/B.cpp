#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e2 + 5;

int n, m;
int ok[maxn][maxn];

void init () {

}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1, k; i <= m; ++i) {
		cin >> k;
		for (int j = 1, x; j <= k; ++j) {
			cin >> x;
			ok[i][x] = true;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			bool yes = false;
			for (int p = 1; p <= m; ++p) {
				if (ok[p][i] && ok[p][j]) {
					yes = true;
					break;
				}
			}
			if (!yes) {
				cout << "No" << endl;
				return;
				
			}
		}
	}
	cout << "Yes" << endl;
}

signed main () {
	charming ();
	return 0;
}