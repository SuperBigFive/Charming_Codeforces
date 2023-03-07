#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <vector <int> > ans (n + 1, vector <int> (n + 1));
	if (n & 1) {
		int p1 = 1, p2 = n * n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (((i - 1) * n + j) & 1) ans[i][j] = p1++;
				else ans[i][j] = p2--;
			}
		}
	}
	else {
		int p1 = 1, p2 = n * n;
		for (int i = 1; i <= n; ++i) {
			if (i & 1) {
				for (int j = 1; j <= n; ++j) {
					if (j & 1) ans[i][j] = p1++;
					else ans[i][j] = p2--;
				}
			}
			else {
				for (int j = n; j >= 1; --j) {
					if ((n - j + 1) & 1) ans[i][j] = p1++;
					else ans[i][j] = p2--;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << ans[i][j] << " \n"[j == n];
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}