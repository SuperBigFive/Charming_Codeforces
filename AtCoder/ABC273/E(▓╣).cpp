#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n, m, tot;
int root[maxn], old_siz[maxn], page[maxn];
int node[maxn << 5], ls[maxn << 5], rs[maxn << 5];

void init () {
	
}

void build (int cnt, int l, int r) {
	if (l == r) {
		node[cnt] = 0;
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
	cin >> n;
	build (0, 1, n);
	string opt;
	int v, cur = 0, last = 0, siz = 0, cnt = 0;
	map <int, int> vis;
	vector <pair <char, int> > q;
	for (int i = 1; i <= n; ++i) {
		cin >> opt;
		if (opt[0] != 'D') cin >> v;
		if (opt[0] == 'S' || opt[0] == 'L') {
			if (!vis.count (v)) vis[v] = ++cnt;
			v = vis[v];
		}
		q.emplace_back (make_pair (opt[0], v));
	}
	for (int i = 0; i < n; ++i) {
		opt[0] = q[i].first, v = q[i].second;
		if (opt[0] == 'A') {
			cur = modify (cur, 1, n, ++siz, v);	
		}
		else if (opt[0] == 'D') {
			if (siz) cur = modify (cur, 1, n, siz--, 0);
		}
		else if (opt[0] == 'S') {
			page[v] = cur;
			old_siz[v] = siz;
		}
		else {
			cur = page[v];
			siz = old_siz[v];
		}
		int res = query (cur, 1, n, siz);
		cout << (res ? res : -1) << " \n" [i == n];
	}
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}