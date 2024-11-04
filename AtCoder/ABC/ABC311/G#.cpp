#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int M = 305;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <vector <int> > a (n + 5, vector <int> (m + 5));
	vector <vector <ll> > pre (n + 5, vector <int> (m + 5));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			pre[i][j] = a[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
		}
	}
	
	auto Calc = [&] (int x0, int y0, int x1, int y1) -> ll {
		if (x0 > x1) return 0;
		else return pre[x1][y1] - pre[x0 - 1][y1] - pre[x1][y0 - 1] + pre[x0 - 1][y0 - 1];
	};
	
	ll ans = 0;
	for (int mn = 1; mn < M; ++mn) {
		vector <int> last (M);
		for (int r = 1; r <= n; ++r) {
			vector <int> id (m);
			for (int c = 1; c <= m; ++c) {
				if (a[r][c] < mn) last[c] = r;
			}
			iota (id.begin (), id.end (), 1);
			sort (id.begin (), id.end (), [&] (int x,
			int y) {return last[x] < last[y];});
			vector <int> lef (m + 5), rig (m + 5);
			for (int i = 1; i <= m; ++i) lef[i] = i - 1, rig[i] = i + 1;
			for (int i : id) {
				lef[rig[i]] = lef[i];
				rig[lef[i]] = rig[i];
				ans = max (ans, Calc (last[i] + 1, lef[i] + 1, r, rig[i] - 1) * mn);
			}
		}
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}