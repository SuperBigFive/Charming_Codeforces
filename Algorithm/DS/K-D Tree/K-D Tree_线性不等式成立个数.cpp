#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int k = 2;

int n, m, root;
vector <array <int, 2> > game;
int node[N][k], sum[N], ls[N], rs[N], mx[N][k], mn[N][k];

void init () {
	for (int i = 0; i < k; ++i)
	mx[0][i] = -INT_MAX, mn[0][i] = INT_MAX;
}

int build (int l, int r, int d) {
	int mid = l + r >> 1;
	nth_element (game.begin () + l, game.begin () + mid, 
	game.begin () + r + 1, [&] (array <int, 2> &x, array <int, 2> &y) {
	return x[d] < y[d];});
	for (int i = 0; i < k; ++i) node[mid][i] = game[mid][i];
	if (l < mid) ls[mid] = build (l, mid - 1, (d + 1) % k);
	if (r > mid) rs[mid] = build (mid + 1, r, (d + 1) % k);
	for (int i = 0; i < k; ++i) {
		mx[mid][i] = max ({node[mid][i], mx[ls[mid]][i], mx[rs[mid]][i]});
		mn[mid][i] = min ({node[mid][i], mn[ls[mid]][i], mn[rs[mid]][i]});
	}
	sum[mid] = sum[ls[mid]] + sum[rs[mid]] + 1;
	return mid;
}

int check (int s, int p, int x, int y, int z) {return x * s - y * p >= z;}

int query (int rt, int x, int y, int z) {
	int cnt = 0;
	cnt += check (mx[rt][0], mx[rt][1], x, y, z);
	cnt += check (mx[rt][0], mn[rt][1], x, y, z);
	cnt += check (mn[rt][0], mx[rt][1], x, y, z);
	cnt += check (mn[rt][0], mn[rt][1], x, y, z);
	if (cnt == k * k) return sum[rt];
	else if (cnt == 0) return 0;
	int res = check (node[rt][0], node[rt][1], x, y, z);
	if (ls[rt]) res += query (ls[rt], x, y, z);
	if (rs[rt]) res += query (rs[rt], x, y, z);
	return res;
}

void charming () {
	init ();
	cin >> n >> m;
	game.resize (n + 5);
	for (int i = 1; i <= n; ++i) 
	cin >> game[i][0] >> game[i][1];
	root = build (1, n, 0);
	for (int i = 1, x, y, z; i <= m; ++i) {
		cin >> x >> y >> z;
		cout << query (root, x, y, z) << endl;
	}
}

signed main () {
	charming ();
	return 0;
}