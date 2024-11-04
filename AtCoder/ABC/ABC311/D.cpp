#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e2 + 5;

int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	string s;
	vector <vector <int> > isRock (n + 5, vector <int> (m + 5));
	vector <vector <int> > vis (n + 5, vector <int> (m + 5));
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			isRock[i][j] = (s[j - 1] == '#');
		}
	}
	queue <pair <int, int> > q;
	q.push (make_pair (2, 2));
	vis[2][2] = 1;
	vector <vector <int> > rest (n + 5, vector <int> (m + 5));
	while (!q.empty ()) {
		auto [cx, cy] = q.front ();
		q.pop ();
		if (rest[cx][cy]) continue;
		rest[cx][cy] = 1;
		for (int i = 0, nx, ny; i < 4; ++i) {
			nx = cx + dx[i], ny = cy + dy[i];
			while (!isRock[nx][ny]) {
				vis[nx][ny] = true;
				nx += dx[i];
				ny += dy[i];
			}
			if (!rest[nx - dx[i]][ny - dy[i]]) q.push (make_pair (nx - dx[i], ny - dy[i]));
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	ans += vis[i][j];
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}