#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int n, m, k;
int pre[N << 1], rk[N << 1], ans[N];
vector <array <int, 4> > stk;
vector <pair <int, int> > node[N << 2];

void init () {}

int find (int x) {
	if (x == pre[x]) return x;
	return find (pre[x]);
}

void joint (int x, int y) {
	int fx = find (x), fy = find (y);
	if (rk[fx] > rk[fy]) swap (fx, fy);
	stk.emplace_back ((array <int, 4>) {fx, fy, pre[fx], rk[fx] == rk[fy]});
	pre[fx] = fy, rk[fy] += (rk[fx] == rk[fy]);
}

void modify (int rt, int l, int r, int tl, int tr, int x, int y) {
	if (l >= tl && r <= tr) {
		node[rt].emplace_back (make_pair (x, y));
		return;
	}
	int mid = l + r >> 1;
	if (tl <= mid) modify (rt << 1, l, mid, tl, tr, x, y);
	if (tr > mid) modify (rt << 1 | 1, mid + 1, r, tl, tr, x, y);
}

void divide (int rt, int l, int r) {
	bool ok = true;
	int cnt = 0;
	for (auto [x, y] : node[rt]) {
		int fx = find (x), fy = find (y);
		if (fx == fy) {
			ok = false;
			for (int i = l; i <= r; ++i)
			cout << "No" << endl;
			break;
		}
		joint (x, y + n), joint (x + n, y);
		cnt += 2;
	}
	if (ok && l != r) {
		int mid = l + r >> 1;
		divide (rt << 1, l, mid);
		divide (rt << 1 | 1, mid + 1, r);
	}
	else if (ok && l == r) cout << "Yes" << endl;
	while (cnt) {
		auto [x, y, pre_x, rk_x] = stk.back ();
		stk.pop_back ();
		pre[x] = pre_x, rk[y] -= rk_x;
		--cnt;	
	}
}

void charming () {
	init ();
	cin >> n >> m >> k;
	for (int i = 1; i <= n * 2; ++i) pre[i] = i, rk[i] = 1;
	for (int i = 1, x, y, l, r; i <= m; ++i) {
		cin >> x >> y >> l >> r;
		modify (1, 1, k, l + 1, r, x, y);
	}
	divide (1, 1, k);
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}