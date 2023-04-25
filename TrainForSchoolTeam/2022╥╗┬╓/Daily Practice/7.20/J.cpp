#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
#define format pair <int, pair <int, int > >
using namespace std;
const int maxn = 5e2 + 5;

int n, m;
int mmap[maxn][maxn];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool vis[maxn][maxn];
queue <pii> q;
vector <pii> res, meet, tmp1, tmp2;

void init () {}

void bfs (int x, int y) {
	q.push ({x, y});
	vis[x][y] = true;
	meet.clear ();
	meet.pb ({x, y});
	pii now;
	int up = INT_MAX, down = -1, left = INT_MAX, right = -1;
	tmp1.clear (), tmp2.clear ();
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		up = min (up, now.fir);
		down = max (down, now.fir);
		left = min (left, now.se);
		right = max (right, now.se);
		for (int i = 0; i < 4; ++i) {
			if (!vis[now.fir + dx[i]][now.se + dy[i]] && now.fir + dx[i] <= n && now.se + dy[i] <= m && mmap[now.fir + dx[i]][now.se + dy[i]] == mmap[x][y])
			q.push ({now.fir + dx[i], now.se + dy[i]}), vis[now.fir + dx[i]][now.se + dy[i]] = true, meet.pb ({now.fir + dx[i], now.se + dy[i]});
		}
	}
	for (auto it : meet) {
		if ((it.fir - up + it.se - left) & 1) tmp1.pb ({it.fir, it.se});
		else tmp2.pb ({it.fir, it.se});
	}
	if (tmp1.size () < tmp2.size ()) {
		for (auto it : tmp1) {
			res.pb (it);
		}
	}
	else {
		for (auto it : tmp2) {
			res.pb (it);
		}
	}
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cin >> mmap[i][j];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!vis[i][j]) {
				bfs (i, j);
			}
		}
	}
	if (res.size ()) {
		cout << '1' << ' ' << res.size () << endl;
		for (auto it : res) {
			cout << it.fir << ' ' << it.se << ' ' << '1' << endl;
		}
	}
	else {
		cout << 0 << ' ' << 0 << endl;
	}
}

signed main () {
	charming ();
	return 0;
}