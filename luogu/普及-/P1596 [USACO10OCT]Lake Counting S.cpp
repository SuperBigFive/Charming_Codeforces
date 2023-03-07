#include<iostream>
using namespace std;
char map[100][100];
int N, M;
void dfs(int x, int y);
int main() {
	cin >> N >> M;
	int couter = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> map[i][j];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 'W') {
				dfs(i, j);
					++couter;
			}
		}
	}
	cout << couter;
	return 0;
}
void dfs(int x, int y) {
	map[x][y] = '.';
	for (int dx = -1; dx <= 1; ++dx) {
		int nx = x + dx;
		for (int dy = -1; dy <= 1; ++ dy) {
			int ny = y + dy;
			if (nx >= 0 && nx <= N && ny >= 0 && ny <= M && map[nx][ny] == 'W')
				dfs(nx, ny);
		}
	}
}