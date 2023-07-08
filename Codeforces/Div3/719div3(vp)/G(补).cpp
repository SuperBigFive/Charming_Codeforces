#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e3 + 5;

int n, m, w;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void init () {}

void charming () {
	init ();
	cin >> n >> m >> w;
	vector <vector <int> > a (n + 5, vector <int> (m + 5));
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	cin >> a[i][j];
	auto bfs = [&] (int x, int y, vector <vector <int> > &a) 
	-> vector <vector <int> > {
		vector <vector <int> > dis (n + 5, vector <int> (m + 5, LLONG_MAX));
		queue <pair <int, int> > q;
		q.push ({x, y});
		dis[x][y] = 0;
		while (!q.empty ()) {
			auto [cx, cy] = q.front ();
			q.pop ();
			for (int i = 0, nx, ny; i < 4; ++i) {
				nx = cx + dx[i], ny = cy + dy[i];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != -1
				&& dis[nx][ny] >= LLONG_MAX) {
					dis[nx][ny] = dis[cx][cy] + w;
					q.push ({nx, ny});
				}
			}
	}
	return dis;
	};
	vector <vector <int> > dis_d = bfs (1, 1, a);
	vector <vector <int> > dis_s = bfs (n, m, a);
	int mn_d = LLONG_MAX / 2, mn_s = LLONG_MAX / 2;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j) {
		if (a[i][j] < 1) continue;
		if (dis_d[i][j] < LLONG_MAX) mn_d = min (mn_d, a[i][j] + dis_d[i][j]);
		if (dis_s[i][j] < LLONG_MAX) mn_s = min (mn_s, a[i][j] + dis_s[i][j]);
	}
	if ((mn_d >= LLONG_MAX / 2 || mn_s >= LLONG_MAX / 2) && dis_d[n][m] >= LLONG_MAX) 
	return void (cout << -1 << endl);
	return void (cout << min (dis_d[n][m], mn_d + mn_s) << endl);
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}