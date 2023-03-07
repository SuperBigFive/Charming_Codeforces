#include<iostream>
#include<stdio.h>
using namespace std;
char map[1000][100];
int cnt = 0;
void dfs(int x, int y, int max_x, int max_y);
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			scanf_s(" %c", &map[i][j]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] > '0') {
				dfs(i, j, N, M);
				++cnt;
			}
		}
	}
	cout << cnt;
	return 0;
}
void dfs(int x, int y, int max_x, int max_y) {
	int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
	map[x][y] = '0';
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx <= max_x && ny >= 0 && ny <= max_y && map[nx][ny] > '0')
			dfs(nx, ny, max_x, max_y);
	}
}