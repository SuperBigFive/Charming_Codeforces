#include <bits/stdc++.h>
using namespace std;
const int maxn = 6;

int t;
int sx,sy;
int ans;
bool flag;
int cnt;
int dir[8][2] = {2, 1, 2, -1, -2, 1, -2, -1, 1, 2, 1, -2, -1, 2, -1, -2};
char tmp;
char ideal[maxn][maxn] = {'0','0','0','0','0','0','0','1','1','1','1','1','0','0','1','1','1','1','0','0','0','*','1','1','0','0','0','0','0','1','0','0','0','0','0','0'};
char mmap[maxn][maxn];

void init () {
	flag = false;
	ans = 16;
}

bool check () {
	//if (mmap[3][3] != '*') return false;
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			if (mmap[i][j] != ideal[i][j]) 
			++cnt;
		}
	}
	if (cnt) return false;
	return true;
}

void dfs (int fax, int fay, int x, int y, int depth) {
	if (flag) return;
	cnt = 0;
	if (check()) {
		ans = min (ans, depth);
		return;
	}
	if (depth >= 15 || cnt - 1 > 15 - depth) return;
	/*if (clock() - t > 150) {
		flag = true;
		return;
	}*/
	for (int i = 0; i < 8; ++i) {
		int dx = dir[i][0], dy = dir[i][1];
		if (dx + x == fax && dy + y == fay) continue;
		if (dx + x >= 1 && dx + x <= 5 && dy + y >= 1 && dy + y <= 5) {
			if (mmap[2][4] == '1' && mmap[4][2] == '0' && mmap[1][4] == '1' && mmap[2][5] == '1' && mmap[5][2] == '0' && mmap[4][1] == '0' && mmap[1][5] == '1' && mmap[5][1] == '0' && mmap[dx+x][dy+y] != ideal[x][y] && mmap[dx+x][dy+y] == ideal[dx+x][dy+y] ) continue;
			mmap[x][y] = mmap[dx+x][dy+y];
			mmap[dx+x][dy+y] = '*';
			dfs (x, y, dx + x, dy + y, depth + 1);
			if (flag) return;
			mmap[dx+x][dy+y] = mmap[x][y];
			mmap[x][y] = '*';
		}
	}
}

void solve () {
	init ();
	for (int i = 1; i <= 5; ++i) {
		cin >> mmap[i] + 1;
	}
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			if (mmap[i][j] == '*') {
				sx = i, sy = j;
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	flag = false;
	int t = clock ();
	dfs (-10, -10, sx, sy, 0);
	//cout << clock () - t << "ms" << endl; 
	if (ans > 15) cout << -1 << endl;
	else cout << ans << endl;
}

int main (void) {
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL); 
	cin >> t;
	while (t--) solve();
}
