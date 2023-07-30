#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m, k, H;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> k >> H;
	vector <int> h (n + 5);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
		bool ok = false;
		for (int j = 1; j <= m; ++j) {
			for (int p = 1; p <= m; ++p) {
				if (j == p) continue;
				if (abs (H - h[i]) == abs (j - p) * k) ok = true;
			}
		}
		if (ok) ++ans;
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}