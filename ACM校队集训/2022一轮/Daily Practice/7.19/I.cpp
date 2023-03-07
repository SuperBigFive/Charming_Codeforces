#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back 
#define fir first
#define se second
using namespace std;
const int maxn = 50 + 5;

int n, m, q, now_x, now_y, now_dir = 8 * 500, now_v = 0;
char mmap[maxn][maxn];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void init () {
	
}


void charming () {
	init ();
	cin >> n >> m;
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			mmap[i][j] = '#';
		}
	}
	char ch;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> ch;
			mmap[i][j] = ch;
			if (ch == '*') now_x = i, now_y = j, mmap[i][j] = '.';
		}
	}
	cin >> q;
	char opt, dis, dir;
	for (int i = 1; i <= q; ++i) {
		cin >> opt;
		if (opt == 'L') {
			--now_dir;
		}
		else if (opt == 'R') {
			++now_dir;
		}
		else if (opt == 'U') {
			++now_v;
		}
		else now_v = max (now_v - 1, (ll)0);
		dis = now_v, dir = now_dir % 8;
		while (dis) {
			if (dir & 1) {
				if (mmap[now_x + dx[dir]][now_y + dy[dir]] == '#' || (mmap[now_x + dx[dir]][now_y] == '#' && mmap[now_x][now_y + dy[dir]] == '#')) {
					cout << "Crash! " << now_x << ' ' << now_y << endl;
					now_v = 0;
					break;
				}
			}
			else {
				if (mmap[now_x + dx[dir]][now_y + dy[dir]] == '#') {
					cout << "Crash! " << now_x << ' ' << now_y << endl;
					now_v = 0;
					break;
				}
			}
			now_x += dx[dir], now_y += dy[dir];
			--dis;
		}
		if (!dis) {
			cout << now_x << ' ' << now_y << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}