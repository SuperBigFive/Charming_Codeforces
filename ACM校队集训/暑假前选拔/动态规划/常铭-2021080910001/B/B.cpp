#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;

struct Node {
	int val;
	int x;
	int y;
}node[maxn*maxn];
int n, m, tot1, tot2, tmp, oldd, neww;
int i, j, k;
int pointx[4], pointy[4];
bool mmap[maxn][maxn];

bool cmp (Node a, Node b) {
	return a.val > b.val;
}

void init () {
	tot1 = tot2 = 0;
}

bool check (int cnt) {
	for (k = 0; k < 4 ; ++k) {
		tmp = abs (pointx[k] - node[cnt].x) + abs (pointy[k] - node[cnt].y);
		if (tmp > m) return false;
	}
	return true;
}

void updata (int cnt) {
	oldd = pointx[0] + pointy[0];
	neww = node[cnt].x + node[cnt].y;
	if (neww <= oldd) {
		pointx[0] = node[cnt].x;
		pointy[0] = node[cnt].y;
	}
	oldd = pointx[1] + n - pointy[1];
	neww = node[cnt].x + n - node[cnt].y;
	if (neww <= oldd) {
		pointx[1] = node[cnt].x;
		pointy[1] = node[cnt].y;
	}
	oldd = n - pointx[2] + pointy[2];
	neww = n - node[cnt].x + node[cnt].y;
	if (neww <= oldd) {
		pointx[2] = node[cnt].x;
		pointy[2] = node[cnt].y;
	}
	oldd = n - pointx[3] + n - pointy[3];
	neww = n - node[cnt].x + n - node[cnt].y;
	if (neww <= oldd) {
		pointx[3] = node[cnt].x;
		pointy[3] = node[cnt].y;
	}
}

void solve () {
	cin >> n >> m;
	for (i = 1 ; i <= n; ++i) {
		for (j = 1; j <= n; ++j){
			node[++tot1].x = i;
			node[tot1].y = j;
			cin >> node[tot1].val;
		}
	}
	sort (node + 1, node + 1 + tot1, cmp);
	mmap[node[1].x][node[1].y] = true;
	++tot2;
	for (i = 0; i < 4; ++i) {
		pointx[i] = node[1].x;
		pointy[i] = node[1].y;
	}
	for (i = 2 ; i <= tot1 ; ++i) {
		if (check (i)) {
			++tot2;
			mmap[node[i].x][node[i].y] = true;
			updata (i);
		}
	}
	cout << tot2 << endl;
	for (i = 1; i <= n; ++i) 
	for (j = 1; j <= n ; ++j)
		if (mmap[i][j]) cout << i << " " << j << endl;
}

int main(void) {
	ios::sync_with_stdio (false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve ();
}
