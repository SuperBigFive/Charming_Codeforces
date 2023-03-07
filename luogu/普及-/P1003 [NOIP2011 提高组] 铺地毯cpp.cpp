#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int pos[10000][4];
	for (int i = 0; i < N; ++i) {
		cin >> pos[i][0] >> pos[i][1] >> pos[i][2] >> pos[i][3];
	}
	int x, y,number=-1;
	cin >> x >> y;
	for (int i = 0; i < N; ++i) {
		if (pos[i][0] <= x && pos[i][1] <= y && pos[i][0] + pos[i][2] >= x && pos[i][1] + pos[i][3] >= y) {
			number = i + 1;
		}
	}
	cout << number << endl;
	return 0;
}