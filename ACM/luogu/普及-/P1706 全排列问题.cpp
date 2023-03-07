//DFS求解全排列问题
#include<iostream>
using namespace std;
int n[10] = { 0,1,2,3,4,5,6,7,8,9 };
int state[10];
int temp[10];
int N, couter = 0;
void dfs(int pos, int couter);
int main() {
	cin >> N;
	dfs(1, 0);
	return 0;
}
void dfs(int pos, int couter) {
	if (couter == N) {
		for (int i = 1; i <= N; ++i) {
			cout << "    " << temp[i] ;
			if (i == N) 
				cout << endl;
		}
	}
	for (int i = pos; i <= N; ++i) {
		if (!state[i]) {
			temp[couter+1] = n[i];
			state[i] = 1;
			dfs(1, couter + 1);
			state[i] = 0;
		}
	}
}