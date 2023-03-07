#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
char map[10000][100000];
bool via[10000][10000];
typedef struct position {
	int x;
	int y;
}pos;
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
pos now, nextt;
int ship = 0, N, M;
void bfs(int x, int y);
bool place_valid();
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf(" %c", &map[i][j]);
		}
	}
	if (!place_valid()) {
		cout << "Bad placement." << endl;
		return 0;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == '#') {
				bfs(i, j);
				++ship;
			}
		}
	}
	cout << "There are " << ship << " ships." << endl;
	return 0;
}
void bfs(int x, int y) {
	queue<pos>q;
	now.x = x, now.y = y;
	q.push(now);
	via[x][y] = true;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			nextt.x = now.x + dir[i][0];
			nextt.y = now.y + dir[i][1];
			if (nextt.x >= 0 && nextt.x < N && nextt.y >= 0 && nextt.y < M && (!via[nextt.x][nextt.y]) && map[nextt.x][nextt.y] == '#') {
				q.push(nextt);
				map[nextt.x][nextt.y] = '.';
			}
		}
	}
}
bool place_valid() {
	int nx, ny;
	for(int i = 0; i < N-1; ++i) {
		for (int j = 0; j < M-1; ++j) {
			int Ship = 0, water = 0;
			for (int dx = 0; dx <= 1; ++dx) {
				nx = i + dx;
				for (int dy = 0; dy <= 1; ++dy) {
					ny = j + dy;
					if (map[nx][ny] == '.')
						++water;
					else
						++Ship;
				}
			}
			if (Ship - water == 2)
				return false;
		}
	}
	return true;
}
