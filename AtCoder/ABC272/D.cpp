#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 4e2 + 5;

int n, m, siz;
int dis[maxn][maxn];
vector <int> dx, dy;

void init () {

}

bool check (int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n 
	&& dis[x][y] == INT_MAX;
}

void bfs () {
	for (int i = 1; i <= n; ++i) {
		fill (dis[i], dis[i] + maxn, INT_MAX);
	}
	dis[1][1] = 0;
	queue <pair <int, int> > q;
	q.push (make_pair (1, 1));
	siz = dx.size ();
	pair <int, int> sign[4];
	sign[0] = make_pair (1, 1);
	sign[1] = make_pair (1, -1);
	sign[2] = make_pair (-1, 1);
	sign[3] = make_pair (-1, -1);
	while (!q.empty ()) {
		auto [x, y] = q.front ();
		q.pop ();
		int new_x, new_y;
		for (int i = 0; i < siz; ++i) {
			for (int j = 0; j < 4; ++j) {
				new_x = x + dx[i] * sign[j].first;
				new_y = y + dy[i] * sign[j].second;
				if (check (new_x, new_y)) {
					dis[new_x][new_y] = dis[x][y] + 1;
					q.push (make_pair (new_x, new_y));
				}
			}
		}
	}
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m - i * i == j * j) {
				dx.emplace_back (i);
				dy.emplace_back (j);
			}
		}
	}
	bfs ();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dis[i][j] == INT_MAX) cout << -1 << " ";
			else cout << dis[i][j] << " ";
		}
		cout << endl;
	}
}

signed main () {
	charming ();
	return 0;
}