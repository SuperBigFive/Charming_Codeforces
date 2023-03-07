#include <bits/stdc++.h>
#define ll long long 
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m, tot;
int val[maxn], val_d[maxn], root[maxn];
int node[maxn << 5], ls[maxn << 5], rs[maxn << 5];

void init () {}

void update (int cnt) {node[cnt] = node[ls[cnt]] + node[rs[cnt]];}

int modify (int pre, int l, int r, int pos, int val) {
	int now = ++tot;
	node[now] = node[pre];
	ls[now] = ls[pre], rs[now] = rs[pre];
	if (l == r) {
		node[now] += val;
		return now;
	}
	int mid = l + r >> 1;
	if (pos <= mid) ls[now] = modify (ls[pre], l, mid, pos, val);
	else rs[now] = modify (rs[pre], mid + 1, r, pos, val);
	update (now);
	return now;
}

int query (int rt1, int rt2, int l, int r, int k) {
	if (l == r) return val_d[l];
	int mid = l + r >> 1;
	if (k > node[ls[rt2]] - node[ls[rt1]]) {
		k -= node[ls[rt2]] - node[ls[rt1]];
		return query (rs[rt1], rs[rt2], mid + 1, r, k);
	}
	return query (ls[rt1], ls[rt2], l, mid, k);
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		val_d[i] = val[i];
	}
	sort (val_d + 1, val_d + 1 + n);
	for (int i = 1; i <= n; ++i) {
		val[i] = lower_bound (val_d + 1, val_d + 1 + n, val[i]) - val_d;
		root[i] = modify (root[i - 1], 1, n, val[i], 1);
	}
	for (int i = 1, l, r, k; i <= m; ++i) {
		cin >> l >> r >> k;
		cout << query (root[--l], root[r], 1, n, k) << endl;
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}