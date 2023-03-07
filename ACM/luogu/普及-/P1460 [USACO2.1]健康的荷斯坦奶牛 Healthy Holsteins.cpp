#include <iostream>
using namespace std;
int opti[100] = { 100 };//最优的选用的饲料的组合的编号
int temp[100];
int kind = 0;//已选饲料种类
bool sat();//判断是否已满足牛的需要
void dfs(int pos, int kind);//深搜
int v[100];//所需的各种营养
int g[100][100];//饲料编号
int V, G;
int main() {
	cin >> V;
	for (int i = 0; i < V; ++i)
		cin >> v[i];
	cin >> G;
	for (int i = 0; i < G; ++i) {
		for (int j = 0; j < V; ++j) {
			cin >> g[i][j];
		}
	}
	dfs(0, 0);
	cout << opti[0] << " ";
	for (int i = 1; i < opti[0]; ++i)
		cout << opti[i]+1 << " ";
	cout << opti[opti[0]]+1;
	return 0;
}
bool sat() {
	for (int i = 0; i < V; ++i) {
		int t = 0;
		for (int j = 1; j <= temp[0]; ++j)
			t += g[temp[j]][i];
		if (t < v[i])
			return false;
	}
	return true;
}
void dfs(int pos, int kind) {
	if (kind >= opti[0] || pos > G)
		return;
	if (sat()) {
		opti[0] = kind;
		for (int i = 1; i <= V; ++i)
			opti[i] = temp[i];
		return;
	}
	temp[kind + 1] = pos;
	temp[0] = kind + 1;
	dfs(pos + 1, kind + 1);
	temp[0] = kind;
	dfs(pos + 1, kind);
}