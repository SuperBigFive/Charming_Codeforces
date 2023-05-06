#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
mt19937 rnd (random_device {} ());

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int mp[25][25];

void init () {}

void charming () {
	init ();
	cout << "20 20" << endl;
	for (int i = 1; i <= 20; ++i)
	for (int j = 1; j <= 20; ++j) {
		if (i == 1 && (j <= 10) || (j & 1) || i == 20 && (j > 10)) cout << 1;
		else cout << 0;
		if (j == 20) cout << endl;
	}
	/*memset (mp, 1, sizeof mp);
	for (int i = 1; i <= 23; ++i)
	for (int j = 1; j <= 23; ++j)
	mp[i][j] = 0;
	int cx = 2, cy = 2, dir = 0;
	int nx, ny;
	mp[2][2] = 1;
	int cnt = 0;
	while (cnt < 10000000) {
		mp[cx][cy] = 1;
		nx = cx + dx[dir];
		ny = cy + dy[dir];
		if (mp[nx + dx[dir]][ny + dy[dir]]) 
		dir = (dir + 1) % 4, ++cnt;
		cx = cx + dx[dir], cy = cy + dy[dir];
	}
	mp[13][12] = 0;
	cout << 20 << " " << 20 << endl;
	for (int i = 3; i <= 22; ++i)
	for (int j = 2; j <= 21; ++j) {
		cout << mp[i][j];	
		if (j == 21) cout << endl;
	}*/
}

signed main () {
  charming ();
  return 0;
}