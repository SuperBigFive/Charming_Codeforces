#include<iostream>
#include<algorithm>
using namespace std;
int pre[10000];
int n, m;
int find(int x) {
	int r = x;
	while (r != pre[r]) {
		r = pre[r];
	}
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
typedef struct Road {
	int x;
	int y;
	int time;
}Road;
Road road[100000];
/*void Shell_sort() {
	for (int d = m / 2; d >= 1; d = d / 2) {
		for (int i = 0; i < d; ++i) {
			for (int k = d; i + k < m; k += d) {
				int j = i + k;
				Road temp = road[j];
				while (road[j].time < road[j - d].time && j >= d) {
					road[j] = road[j - d];
					road[j - d] = temp;
					j -= d;
				}
			}
		}
	}
}*/
bool cmp1(Road x, Road y) {
	return x.time < y.time;
}
int main() {
	int Time;
	int couter=0;
	int fx,fy;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> road[i].x >> road[i].y >> road[i].time;
	}
	for (int i = 1; i <= n; ++i) {
		pre[i] = i;
	}
	sort(road, road + m, cmp1);
	for (int i = 0; i < m; ++i) {
		fx=find(road[i].x),fy=find(road[i].y);
		if (fx != fy) {
			pre[fx]=fy;
			Time = road[i].time;
			++couter;
		}
	}
	couter!=n-1?cout << "-1" << endl:cout<<Time<<endl; 
	return 0;
}
