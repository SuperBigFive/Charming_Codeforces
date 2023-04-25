#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int n, m, tot;
int root[maxn], val[maxn];
int node[maxn << 6], ls[maxn << 6], rs[maxn << 6];

void init () {
	
}

void build (int cnt, int l, int r) {
	if (l == r) {
		node[cnt] = val[l];
		return;
	}
	int mid = l + r >> 1;
	build (ls[cnt] = ++tot, l, mid);
	build (rs[cnt] = ++tot, mid + 1, r);
}

int modify (int pre, int l, int r, int pos, int val) {
	int now = ++tot;
	ls[tot] = ls[pre], rs[tot] = rs[pre];
	if (l == r) {
		node[now] = val;
		return now;
	}
	int mid = l + r >> 1;
	if (pos <= mid) ls[now] = modify (ls[pre], l, mid, pos, val);
	else rs[now] = modify (rs[pre], mid + 1, r, pos, val);
	return now;
}

int query (int cnt, int l, int r, int pos) {
	if (l == r) return node[cnt];
	int mid = l + r >> 1;
	if (pos <= mid) return query (ls[cnt], l, mid, pos);
	return query (rs[cnt], mid + 1, r, pos);
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> val[i];
	build (0, 1, n);
	int opt, v, loc, value;
	for (int i = 1; i <= m; ++i) {
		cin >> v >> opt;
		if (opt == 1) {
			cin >> loc >> value;
			root[i] = modify (root[v], 1, n, loc, value);	
		}
		else {
			cin >> loc;
			root[i] = root[v];
			cout << query (root[v], 1, n, loc) << endl;
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}