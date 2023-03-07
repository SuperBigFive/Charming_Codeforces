#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e2 + 5;

int t, n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int vis_x[maxn], vis_y[maxn];

void init () {
	fill (vis_x, vis_x + maxn, 0);
	fill (vis_y, vis_y + maxn, 0);
}

void charming () {
	init ();
	cin >> n >> m;
	vector <pair <int, int> > rook;
	for (int i = 1, x, y; i <= m; ++i) {
		cin >> x >> y;
		++vis_x[x];
		++vis_y[y];
		rook.emplace_back (make_pair (x, y));
	}
	for (auto [x, y] : rook) {
		--vis_x[x];
		--vis_y[y];
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n 
			&& !vis_x[nx] && !vis_y[ny]) {
				cout << "YES" << endl;
				return;
			}
		}
		++vis_x[x];
		++vis_y[y];
	}
	cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}