#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m;
int a[N], pre[N], vis[N], siz[N];
int node[N], dist[N], fa[N];
int ch[N][2];

void init () {}

int find (int x) {
	if (x == pre[x]) return x;
	else return pre[x] = find (pre[x]);
}

int Get_rs (int x) {return dist[ch[x][1]] <= dist[ch[x][0]];}

void PushUp (int x) {
	if (!x) return;
	else {
		int rs = Get_rs (x);
		if (dist[x] != dist[ch[x][rs]] + 1) {
			dist[x] = dist[ch[x][rs]] + 1;
			PushUp (fa[x]);
		}
	}
}

int Merge (int x, int y) {
	if (!x || !y) return x | y;
	if (node[x] > node[y] || (node[x] == node[y] && x > y)) swap (x, y);
	int rs = Get_rs (x);
	ch[x][rs] = Merge (ch[x][rs], y);
	fa[ch[x][rs]] = x;
	PushUp (x);
	return x;
}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> node[i];
		dist[i] = 1, pre[i] = i;	
	}
	for (int i = 1, opt, x, y, fx, fy; i <= m; ++i) {
		cin >> opt >> x;
		fx = find (x);
		if (opt == 1)	{
			cin >> y;
			fy = find (y);
			if (fx == fy || vis[x] || vis[y]) continue;
			else pre[fx] = pre[fy] = Merge (fx, fy);
		} else if (vis[x]) cout << -1 << endl;
		else {
			cout << node[fx] << endl;
			vis[fx] = 1;
			pre[ch[fx][0]] = pre[ch[fx][1]] = pre[fx] = 
			Merge (ch[fx][0], ch[fx][1]);
			ch[fx][0] = ch[fx][1] = dist[fx] = pre[0] = 0;
		}
	}
}

signed main () {
	charming ();
	return 0;
}