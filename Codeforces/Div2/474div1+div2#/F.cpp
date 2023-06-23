#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 1e5 + 5;
const int M = 2e7 + 5;

int tot;
int root[N];
int mx[M], ls[M], rs[M];

void Modify (int &rt, int l, int r, int p, int k) {
	if (!rt) rt = ++tot;
	mx[rt] = max (mx[rt], k);
	if (l == r) return;
	int mid = l + r >> 1;
	if (p <= mid) Modify (ls[rt], l, mid, p, k);
	else Modify (rs[rt], mid + 1, r, p, k);
}
	
int Query (int rt, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return mx[rt];
	int mid = l + r >> 1, ans = 0;
	if (ql <= mid) ans = max (ans, Query (ls[rt], l, mid, ql, qr));
	if (qr > mid) ans = max (ans, Query (rs[rt], mid + 1, r, ql, qr));
	return ans;
}

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	for (int i = 0, u, v, w, umx, vmx; i < m; ++i) {
		cin >> u >> v >> w;
		--u, --v;
		umx = Query (root[u], -1, N, -1, w - 1);
		Modify (root[v], -1, N, w, umx + 1);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) ans = max (ans, mx[root[i]]);
	cout << ans << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}