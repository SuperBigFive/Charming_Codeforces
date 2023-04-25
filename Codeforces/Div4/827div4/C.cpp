#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 10 + 5;

int t, n;
char mp[maxn][maxn];

void init () {}

void charming () {
	init ();
	n = 8;
	char ch;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> ch;
			mp[i][j] = ch;
		}
	}
	int ans = -1;
	for (int i = 1, st; i <= n; ++i) {
		if (mp[i][1] != 'R') continue;
		bool ok = true;
		for (int j = 1; j <= n; ++j) {
			if (mp[i][j] != 'R') {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << 'R' << endl;
			return;
		}
	}
	cout << 'B' << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}