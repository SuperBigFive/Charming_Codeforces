#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

int t, n, k;
int fac[N], inv[N];
pair <int, int> node[N << 2], dp[N], dp_pre[N];

void init () {
	for (int i = 0; i <= n; ++i)
	dp[i] = dp_pre[i] = make_pair (0, 0);
}

int qsm (int x, int p) {
	int ans = 1;
	while (p) {
		if (p & 1) ans = (ans * x) % MOD;
		p >>= 1, x = (x * x) % MOD;
	}
	return ans;
}

void get_fac_inv () {
	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = (fac[i - 1] * i) % MOD;
		inv[i] = qsm (fac[i], MOD - 2);
	}
}

int C (int n, int m) {
	if (n < m) return 0;
	return (((fac[n] * inv[m]) % MOD) * inv[n - m]) % MOD;
}

void build (int rt, int l, int r) {
	node[rt] = make_pair (0, 0);
	if (l == r) return;
	int mid = l + r >> 1;
	build (rt << 1, l, mid);
	build (rt << 1 | 1, mid + 1, r);
}

void pushup (int rt) {
	node[rt].second = max (node[rt << 1].second, node[rt << 1 | 1].second);
	if (node[rt << 1].second != node[rt << 1 | 1].second)
	node[rt].first = node[rt << 1].second > node[rt << 1 | 1].second ? 
	node[rt << 1].first : node[rt << 1 | 1].first;
	else node[rt].first = (node[rt << 1].first + node[rt << 1 | 1].first) % MOD;
}

void modify (int rt, int l, int r, int p, int nsum, int nlen) {
	if (l == r) {node[rt] = make_pair (nsum, nlen); return;}
	int mid = l + r >> 1;
	if (p <= mid) modify (rt << 1, l, mid, p, nsum, nlen);
	else modify (rt << 1 | 1, mid + 1, r, p, nsum, nlen);
	pushup (rt);
}

pair <int, int> query (int rt, int l, int r, int qr) {
	if (qr < 1) return make_pair (0, 0);
	if (r <= qr) return node[rt];
	int mid = l + r >> 1;
	pair <int, int> ans = query (rt << 1, l, mid, qr);
	if (qr > mid) {
		pair <int, int> tmp = query (rt << 1 | 1, mid + 1, r, qr);
		if (ans.second < tmp.second) ans = tmp;
		else if (ans.second == tmp.second) ans.first = (ans.first + tmp.first) % MOD;
	}
	return ans;
}

void charming () {
	init ();
	cin >> n >> k;
	build (1, 1, n);
	vector <int> a (n + 5), p (n + 5);
	vector <vector <int> > pos (n + 5);
	bool NoMoreK = true;
	for (int i = 1, siz; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]].emplace_back (i);
		if (pos[a[i]].size () >= k) {
			NoMoreK = false;
			siz = pos[a[i]].size ();
			pair <int, int> cbest;
			for (int j = siz - k; j >= 0; --j) {
				auto nbest = dp_pre[pos[a[i]][j] - 1];
				if (nbest.second == 0) nbest.first = 1;
				if (nbest.second < cbest.second) continue;
				else if (nbest.second == cbest.second) cbest.first = (cbest.first + 
				nbest.first * C (siz - j - 2, k - 2) % MOD) % MOD;
				else cbest = nbest;
			}
			++cbest.second, dp[i] = cbest;
			modify (1, 1, n, i, dp[i].first, dp[i].second);
		}
		dp_pre[i] = query (1, 1, n, i);
	}
	if (k == 1 || NoMoreK) return void (cout << 1 << endl);
	int mx_len = 0, ans = 0;
	for (int i = 1; i <= n; ++i) mx_len = max (mx_len, dp[i].second);
	for (int i = 1; i <= n; ++i) if (dp[i].second == mx_len) ans = (ans + dp[i].first) % MOD;
	ans = ((ans % MOD) + MOD) % MOD;
	cout << ans << endl;
}

signed main () {
	get_fac_inv ();
	cin >> t;
	while (t--) charming ();
	return 0;
}