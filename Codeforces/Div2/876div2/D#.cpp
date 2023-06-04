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
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	a[n + 1] = n + 1;
	vector <vector <int> > dp1 (n + 5, vector <int> (n + 5));
	vector <vector <int> > dp2 (n + 5, vector <int> (n + 5));
	vector <vector <int> > ans (n + 5, vector <int> (n + 5));
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			int p2 = n + 1;
			while (p2 - 1 >= i && a[p2 - 1] < a[p2] && a[p2 - 1] > a[i]) --p2;
			dp2[i][k] = n - p2 + 1;
			vector <int> stk;
			for (int j = i, p = n; j >= 1; --j) {
				if (j < i && a[j] > a[j + 1]) break;
				else stk.emplace_back (j);
			}
			if (k == 1) {
				if (stk.back () != 1) continue;
				else ans[a[i]][k] = dp1[i][k] = i;
			} else {
				int p1 = 1, mx = 0;
				while (stk.size ()) {
					int j = stk.back ();
					stk.pop_back ();
					while (p1 < a[j]) mx = max (mx, ans[p1][k - 1]), ++p1;
					dp1[i][k] = max (dp1[i][k], i - j + 1 + mx);
				}
				ans[a[i]][k] = dp1[i][k];
			}
		}
	}
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		res = n;
		for (int j = 1; j <= n; ++j) res = min (res, n - dp1[j][i] - dp2[j][i]);
		if (i == 1) {
			int p2 = n;
			while (p2 - 1 >= 1 && a[p2 - 1] < a[p2]) --p2;
			res = min (res, p2 - 1);
		}
		cout << res << " \n"[i == n];
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}