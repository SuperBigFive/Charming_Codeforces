#include<iostream>
#include<algorithm>
using namespace std;
int find(int x);
typedef struct edge {
	int road1;
	int road2;
	int weight;
}edge;
edge e[100000];
int pre[301];
bool cmp(edge e1, edge e2);
int main() {
	int n, m,cnt=0,max;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> e[i].road1 >> e[i].road2 >> e[i].weight;
	}
	for (int i = 0; i < n; ++i)
		pre[i] = i;
	sort(e, e + m, cmp);
	for (int i = 0; i < m; ++i) {
		int fx = find(e[i].road1), fy = find(e[i].road2);
		if (fx != fy) {
			pre[fx] = fy;
			max = e[i].weight;
			if (++cnt == n - 1) {
				cout << n - 1 << " " << max << endl;
				return 0;
			}
		}
	}
	cout << "error" << endl;
	return 0;
}
int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}
bool cmp(edge e1, edge e2) {
	return e1.weight < e2.weight;
}
