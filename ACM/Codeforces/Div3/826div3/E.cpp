/*
4 6 2 3 7 2 6 2 4 1 2 4 7 3 7 1
*/

#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n, tot, ok;
int b[maxn];
int to[maxn], nxt[maxn], st[maxn], head[maxn];
bool vis[maxn];

void init () {
	for (int i = 0; i <= tot; ++i)
	to[i] = nxt[i] = st[i] = head[i] = vis[i] = 0;
	tot = ok = 0;
}

void add_edge (int u, int v, int statu) {
	to[++tot] = v;
	nxt[tot] = head[u];
	st[tot] = statu;
	head[u] = tot;
}
	
void dfs (int cur, int statu) {
	if ((!statu && cur == n) || (statu && cur + b[cur] == n)) {
		ok = true;
		return;
	}
	if (cur + statu * b[cur] > n) return;
	for (int i = head[cur + statu * b[cur]], v, s; i; i = nxt[i]) {
		if (vis[i]) continue;
		vis[i] = true;
		v = to[i], s = st[i];
		dfs (v, s);
		if (ok) return;
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		if (i == 1 && i + b[i] <= n) add_edge (0, i, 1);
		else if (i > 1) add_edge (i - 1, i, 1);
		if (i - b[i] - 1 >= 0) add_edge (i - b[i] - 1, i, 0);
	}
	dfs (0, 1);
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}