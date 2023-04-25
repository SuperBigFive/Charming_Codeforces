#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 5e5 + 5;
const int M = 1e9 + 5 + N;

int n, k, rt, tot;
int node[N << 5], ls[N << 5], rs[N << 5];

void init () {
	for (int i = 0; i <= tot; ++i)
	node[i] = ls[i] = rs[i] = 0;
	rt = tot = 1;
}

void modify (int &cnt, int l, int r, int ql, int qr, int k) {
	if (!cnt) cnt = ++tot;
	if (l >= ql && r <= qr) {node[cnt] = k; return;}
	int mid = l + r >> 1;
	if (ql <= mid) modify (ls[cnt], l, mid, ql, qr, k);
	if (qr > mid) modify (rs[cnt], mid + 1, r, ql, qr, k);
	node[cnt] = max (node[ls[cnt]], node[rs[cnt]]);
}

int query (int cnt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return node[cnt];
	int mid = l + r >> 1, res = 0;
	if (ql <= mid) res = max (res, query (ls[cnt], l, mid, ql, qr));
	if (qr > mid) res = max (res, query (rs[cnt], mid + 1, r, ql, qr));
	return res;
}

void charming () {
	init ();
	cin >> n >> k;
	vector <int> a (n + 5), b (k + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i], a[i] = a[i] - i + N;
	for (int i = 1; i <= k; ++i) cin >> b[i];
	b[++k] = n + 1, a[n + 1] = M;
	auto solve = [&] (int l, int r) -> int {
		init ();
		vector <int> dp (r - l + 5);
		int ans = 0;
		for (int i = l + 1; i < r; ++i) {
			if (a[i] < a[l] || a[i] > a[r]) continue;
			dp[i - l] = query (rt, 1, M, 1, a[i]) + 1;
			modify (rt, 1, M, a[i], a[i], dp[i - l]);
			ans = max (ans, dp[i - l]);
		}
		return r - l - 1 - ans;
	};
	int res = 0;
	for (int i = 1; i <= k; ++i) {
		if (a[b[i]] < a[b[i - 1]]) {
			cout << -1 << endl;
			return;
		}
		res += solve (b[i - 1], b[i]);
	}
	cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}