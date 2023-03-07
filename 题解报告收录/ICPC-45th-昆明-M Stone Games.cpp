#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5;
const int mx = 1e9;

int n, m, tot;
int val[maxn], root[maxn];
ll sum[maxn << 5];
int ls[maxn << 5], rs[maxn << 5];

void init () {}

void update (int cnt) {sum[cnt] = sum[ls[cnt]] + sum[rs[cnt]];}

int modify (int pre, int l, int r, ll k) {
	int now = ++tot;
	sum[now] = sum[pre];
	if (l == r) {
		sum[now] += k;
		return now;
	}
	ls[now] = ls[pre], rs[now] = rs[pre];
	int mid = l + r >> 1;
	if (k <= mid) ls[now] = modify (ls[pre], l, mid, k);
	else rs[now] = modify (rs[pre], mid + 1, r, k);
	update (now);
	return now;
}

ll query (int rt1, int rt2, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return sum[rt2] - sum[rt1];
	int mid = l + r >> 1;
	ll res = 0;
	if (ql <= mid) res += query (ls[rt1], ls[rt2], l, mid, ql, qr);
	if (qr > mid) res += query (rs[rt1], rs[rt2], mid + 1, r, ql, qr);
	return res;
}

void charming () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		root[i] = modify (root[i - 1], 1, mx, val[i]);
	}
	int l, r;
	ll ans = 0, s;
	for (int i = 1; i <= m; ++i) {
		cin >> l >> r;
		l = (l + ans) % n + 1, r = (r + ans) % n + 1;
		if (l > r) swap (l, r);
		ans = 0;
		while (true) {
			s = query (root[l - 1], root[r], 1, mx, 1, min (1ll * mx, ans + 1));
			if (s <= ans) break;
			ans = s;
		}
		cout << ++ans << endl;
	}
}

signed main () {
	charming ();
	return 0;
}