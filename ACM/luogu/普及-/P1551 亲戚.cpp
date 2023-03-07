#include<iostream>
using namespace std;
int pre[10000];
int find(int x) {
	int r = x;
	while (r != pre[r])
		r = pre[r];
	int i = x, j;
	while (i != r) {
		j = i;
		i = pre[i];
		pre[j] = r;
	}
	return r;
}
void joint(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy)
		pre[fy] = fx;
}
bool relative(int x, int y) {
	if (find(x) == find(y))
		return true;
	else
		return false;
}
int main() {
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 1; i <= n; ++i) {
		pre[i] = i;
	}
	int rel1, rel2;
	for (int i = 0; i < m; ++i) {
		cin >> rel1 >> rel2;
		joint(rel1, rel2);
	}
	for (int i = 0; i < p; ++i) {
		cin >> rel1 >> rel2;
		relative(rel1,rel2)?cout << "Yes" << endl:cout << "No" << endl;
	}
	return 0;
}