#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	array <int, 3> cnt;
	array <vector <int>, 3> can;
	array <vector <int>, 3> pre;
	for (int i = 0; i < 3; ++i) {
		cnt[i] = 0;
		can[i].emplace_back (0);
		pre[i].resize (n + 5);
	}
	for (int i = 1, type, x; i <= n; ++i) {
		cin >> type >> x;
		can[type].emplace_back (x);
		++cnt[type];
	}
	for (int i = 0; i < 3; ++i) {
		sort (can[i].begin () + 1, can[i].end (), [] (int &x, int &y) {return x > y;});
		for (int j = 1; j <= n; ++j) {
			if (j <= cnt[i]) pre[i][j] = can[i][j] + pre[i][j - 1];
			else pre[i][j] = pre[i][j - 1];
		}
	}
	
	auto BinarySearch = [&] (int c, int mx) -> ll {
		ll ans = 0;
		int l = 0, r = min ({cnt[1], mx, c});
		while (l <= r) {
			if (r - l <= 10) {
				for (int i = l; i <= r; ++i) {
					ans = max (ans, pre[1][i] + pre[0][c - i]);
				}
				return ans;
			}
			int mid1 = (l + (r - l) / 3), chk1 = pre[1][mid1] + pre[0][c - mid1];
			int mid2 = (r - (r - l) / 3), chk2 = pre[1][mid2] + pre[0][c- mid2];
			if (chk1 <= chk2) l =  mid1 + 1;
			else r = mid2 - 1;
		}
	};
	
	ll ans = 0;
	for (int i = 0, siz = min (m, cnt[2]); i <= siz; ++i) {
		ans = max (ans, BinarySearch (m - i, pre[2][i]));
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}