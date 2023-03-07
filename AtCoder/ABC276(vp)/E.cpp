#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int h, w, sx, sy, cnt;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int siz[maxn];
vector <vector <char> > mp;
map <int, int> vis[maxn];

void init () {}

bool check (int x, int y) {
	return x >= 1 && x <= h && 
	y >= 1 && y <= w && mp[x][y] == '.';
}

void bfs (int x, int y) {
	queue <pair <int, int> > q;
	q.push (make_pair (x, y));
	pair <int, int> cur;
	++siz[cnt];
	vis[x][y] = cnt;
	while (!q.empty ()) {
		cur = q.front ();
		q.pop ();
		for (int i = 0, nx, ny; i < 4; ++i) {
			nx = cur.first + dx[i];
			ny = cur.second + dy[i];
			if (check (nx, ny) && !vis[nx][ny]) {
				vis[nx][ny] = cnt;
				q.push (make_pair (nx, ny));
				++siz[cnt];
			}
		}
	}
}

void charming () {
	init ();
	cin >> h >> w;
	mp.resize (h + 5);
	for (int i = 1; i <= h; ++i) {
		mp[i].emplace_back ('#');
		for (int j = 1; j <= w; ++j) {
			char ch;
			cin >> ch;
			mp[i].emplace_back (ch);
			if (ch == 'S') sx = i, sy = j;
		}
	}

	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			if (mp[i][j] == '.' && !vis[i][j])
			++cnt, bfs (i, j);
		}
	}
	for (int i = 0, nx1, ny1; i < 4; ++i) {
		for (int j = 0, nx2, ny2; j < 4; ++j) {
			if (i == j) continue;
			nx1 = sx + dx[i], ny1 = sy + dy[i];
			nx2 = sx + dx[j], ny2 = sy + dy[j];
			if (!check (nx1, ny1) || !check (nx2, ny2)) continue;
			if (vis[nx1][ny1] == vis[nx2][ny2]) {
				cout << "Yes" << endl;
				return;
			}
		}
	}
	cout << "No" << endl;
}

signed main () {
	charming ();
	return 0;
}