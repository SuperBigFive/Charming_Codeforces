#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 55;

int t, n, A, B;
int vis[N][N][N][N];

void init () {memset (vis, 0, sizeof vis);}

void charming () {
	init ();
	cin >> n >> A >> B;
	int mn = INT_MAX;
	string s, res, color;
	cin >> s;
	auto dfs = [&] (auto &&me, int id, int red, int black, int cnt, string &color) {
		if (id >= n) {
			int diff = abs (n - 2 * cnt);
			if (red || black || diff >= mn || cnt < 1 || cnt > n - 1) return;
			mn = diff;
			res = color;
			return;
		}
		if (vis[id][red][black][cnt]) return;
		vis[id][red][black][cnt] = true;
		color.append ("R");
		me (me, id + 1, (red * 10 + s[id] - '0') % A, black, cnt + 1, color);
		color.pop_back ();
		color.append ("B");
		me (me, id + 1, red, (black * 10 + s[id] - '0') % B, cnt, color);
		color.pop_back ();
	};
	dfs (dfs, 0, 0, 0, 0, color);
	if (mn >= INT_MAX) cout << -1 << endl;
	else cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}