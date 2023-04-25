#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e3 + 5;
const int M = 5e6 + 5;

int n, m, tot;
int a[N][N], bel[N], be[N], en[N];
int root_row[M], root_blo[M];
int mx[M], mn[M], ls[M], rs[M];
set <pair <int, int> > s[505][505];

void init () {}

void update (int rt) {
	mx[rt] = max (mx[ls[rt]], mx[rs[rt]]);
	mn[rt] = min (mn[ls[rt]], mn[rs[rt]]);
}

void build_row (int rt, int l, int r, int row) {
	if (l == r) {mx[rt] = mn[rt] = a[row][l]; return;}
	int mid = l + r >> 1;
	build_row (ls[rt] = ++tot, l, mid, row);
	build_row (rs[rt] = ++tot, mid + 1, r, row);
	update (rt);
}

void build_blo (int rt, int l, int r, int row) {
	if (l == r) {
		s[bel[row]][l].insert (make_pair (a[row][l], row));
		mx[rt] = (*(s[bel[row]][l].rbegin ())).first;
		mn[rt] = (*(s[bel[row]][l].begin ())).first;
		return;
	}
	int mid = l + r >> 1;
	if (!ls[rt]) ls[rt] = ++tot;
	build_blo (ls[rt], l, mid, row);
	if (!rs[rt]) rs[rt] = ++tot;
	build_blo (rs[rt], mid + 1, r, row);
	update (rt);
}

void modify_row (int rt, int l, int r, int col, int k) {
	if (l == r) {mx[rt] = mn[rt] = k; return;}
	int mid = l + r >> 1;
	if (col <= mid) modify_row (ls[rt], l, mid, col, k);
	else modify_row (rs[rt], mid + 1, r, col, k);
	update (rt);
}

void modify_blo (int rt, int l, int r, int row, int col, int k) {
	if (l == r) {
		s[bel[row]][col].erase (make_pair (a[row][col], row));
		s[bel[row]][col].insert (make_pair (a[row][col] = k, row));
		mx[rt] = (*(s[bel[row]][col].rbegin ())).first;
		mn[rt] = (*(s[bel[row]][col].begin ())).first;
		return;
	}
	int mid = l + r >> 1;
	if (col <= mid) modify_blo (ls[rt], l, mid, row, col, k);
	else modify_blo (rs[rt], mid + 1, r, row, col, k);
	update (rt);
}

pair <int, int> query (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return make_pair (mx[rt], mn[rt]);
	int mid = l + r >> 1;
	pair <int, int> ans = {-1, INT_MAX}, tmp;
	if (ql <= mid) {
		tmp = query (ls[rt], l, mid, ql, qr);
		ans.first = max (ans.first, tmp.first);
		ans.second = min (ans.second, tmp.second);
	}
	if (qr > mid) {
		tmp = query (rs[rt], mid + 1, r, ql, qr);
		ans.first = max (ans.first, tmp.first);
		ans.second = min (ans.second, tmp.second);
	}
	return ans;
}

void charming () {
	init ();
	cin >> n;
	int len = 25, blo = (n + len - 1) / len;	
	for (int i = 1; i <= n; ++i) {
		bel[i] = (i + len - 1) / len;
		be[i] = (i - 1) * len + 1;
		en[i] = min (n, i * len);
		for (int j = 1; j <= n; ++j)
		cin >> a[i][j];
		build_row (root_row[i] = ++tot, 1, n, i);
		if (!root_blo[bel[i]]) root_blo[bel[i]] = ++tot;
		build_blo (root_blo[bel[i]], 1, n, i);
	}
	cin >> m;
	for (int i = 1, opt, x1, y1, x2, y2, k; i <= m; ++i) {
		cin >> opt >> x1 >> y1;
		if (opt == 1) {
			cin >> k;
			modify_row (root_row[x1], 1, n, y1, k);
			modify_blo (root_blo[bel[x1]], 1, n, x1, y1, k);
		} else {
			cin >> x2 >> y2;
			int blo_1 = bel[x1], blo_2 = bel[x2];
			int mx_val = -1, mn_val = INT_MAX;
			pair <int, int> tmp;
			if (blo_1 + 1 >= blo_2) {
				for (int i = x1; i <= x2; ++i) {
					tmp = query (root_row[i], 1, n, y1, y2);
					mx_val = max (mx_val, tmp.first);
					mn_val = min (mn_val, tmp.second);
				}
			} else {
				int en_1 = en[bel[x1]], be_2 = be[bel[x2]];
				for (int i = x1; i <= en_1; ++i) {
					tmp = query (root_row[i], 1, n, y1, y2);
					mx_val = max (mx_val, tmp.first);
					mn_val = min (mn_val, tmp.second);
				}
				for (int i = be_2; i <= x2; ++i) {
					tmp = query (root_row[i], 1, n, y1, y2);
					mx_val = max (mx_val, tmp.first);
					mn_val = min (mn_val, tmp.second);
				}
				for (int i = blo_1 + 1; i <= blo_2 - 1; ++i) {
					tmp = query (root_blo[i], 1, n, y1, y2);
					mx_val = max (mx_val, tmp.first);
					mn_val = min (mn_val, tmp.second);
				}
			}
			cout << mx_val << " " << mn_val << endl;
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