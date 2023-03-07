#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e3 + 5;

int n, m;
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'L', 'R', 'U'};
int step[maxn][maxn], mov[maxn][maxn];
bool vis[maxn][maxn];
char mp[maxn][maxn];
pair <int, int> be, en;

void init () {
	
}

void put_ans () {
	vector <char> ans_move;
	int now_x = en.first, now_y = en.second;
	int d;
	while (true) {
		if (now_x == be.first && now_y == be.second) break;
		d = mov[now_x][now_y];
		ans_move.emplace_back (dir[d]);
		if (d == 0) d = 3;
		else if (d == 1) d = 2;
		else if (d == 2) d = 1;
		else if (d == 3) d = 0;
		now_x += dx[d], now_y += dy[d];
		while (mp[now_x][now_y] == 'X') now_x += dx[d], now_y += dy[d];
	}
	reverse (ans_move.begin (), ans_move.end ());
	printf ("%lld\n", step[en.first][en.second]);
	for (auto it : ans_move) {
		printf ("%c", it);
	}
	printf ("\n");
	exit (0);
}

void charming () {
	scanf ("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		char ch;
		for (int j = 1; j <= m; ++j) {
			cin >> ch;
			mp[i][j] = ch;
			if (ch == 'S') be.first = i, be.second = j;
			if (ch == 'E') en.first = i, en.second = j;
		}
	}
	queue <pair <int, int> > q;
	pair <int, int> now;
	q.push (be);
	vis[be.first][be.second] = true;
	while (!q.empty ()) {
		now = q.front ();
		q.pop ();
		int now_x, now_y, nxt_x, nxt_y;
		now_x = now.first, now_y = now.second;
		for (int i = 0; i < 4; ++i) {
			nxt_x = now_x + dx[i];
			nxt_y = now_y + dy[i];
			while (nxt_x <= n && nxt_x > 0 && nxt_y <= m && nxt_y > 0
			&& mp[nxt_x][nxt_y] == 'X') nxt_x += dx[i], nxt_y += dy[i];
			if (nxt_x <= n && nxt_x > 0 && nxt_y <= m && nxt_y > 0 
			&& !vis[nxt_x][nxt_y]) {
				step[nxt_x][nxt_y] = step[now_x][now_y] + 1;
				mov[nxt_x][nxt_y] = i;
				vis[nxt_x][nxt_y] = true;
				if (nxt_x == en.first && nxt_y == en.second) put_ans ();
				q.push (make_pair (nxt_x, nxt_y));
			}
		}
	}
	puts ("-1");
}

signed main () {
	charming ();
	return 0;
}