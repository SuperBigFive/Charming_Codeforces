#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e2 + 5;

int h, w, n;

void init () {}

void charming () {
	init ();
	cin >> h >> w >> n;
	bool rev = false;
	if (h > w) swap (h, w), rev = true;
	vector <vector <int> > last (h + 5, vector <int> (w + 5));
	vector <vector <int> > pre (h + 5, vector <int> (w + 5));
	for (int i = 1, a, b; i <= n; ++i) {
		cin >> a >> b;
		if (rev) swap (a, b);
		pre[a][b] = 1;
	}
	for (int i = 1; i <= h; ++i)
	for (int j = 1; j <= w; ++j)
	pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + pre[i][j];
	ll ans = 0;
	
	auto Calc = [&] (int x0, int y0, int x1, int y1) -> int {
		return pre[x1][y1] - pre[x1][y0 - 1] - pre[x0 - 1][y1] + pre[x0 - 1][y0 - 1];
	};
	
	ll sum = 0;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1, l, r, ans; j <= w; ++j) {
			if (Calc (i, j, i, j)) continue;
			l = max (1ll, last[i - 1][j - 1] - 1), r = min (h - i, w - j) + 1, ans = l;
			while (l <= r) {
				int mid = l + r >> 1;
				if (!Calc (i, j, i + mid - 1, j + mid - 1)) l = mid + 1, ans = mid;
				else r = mid - 1;
			}
			sum += (last[i][j] = ans);
		}
	}
	cout << sum << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}