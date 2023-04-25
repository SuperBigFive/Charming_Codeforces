#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e3 + 5;
const int MOD = 998244353;

int n, p, q, inv;
int vis[N][N];

void init () {}

int qsm (int x, int p) {
	int ans = 1;
	while (p) {
		if (p & 1) ans = (ans * x) % MOD;
		p >>= 1, x = (x * x) % MOD;
	}
	return ans;
}

int get_ans (int a, int b) {
	if (a >= n || (n - a - 1) * q + b < n) return 1;
	if (b >= n || (n - b) * p + a < n) return 0;
	if (vis[a][b]) return vis[a][b];
	int ans = 0;
	for (int i = 1; i <= p; ++i)
	for (int j = 1; j <= q; ++j) {
		if (a + i >= n) ans = (ans + 1) % MOD;
		else ans = (ans + get_ans (min (a + i, n), min (b + j, n))) % MOD;
	}
	ans = (ans * inv) % MOD;
	ans = ((ans % MOD) + MOD) % MOD;
	return vis[a][b] = ans;
}

void charming () {
	init ();
	int a, b;
	cin >> n >> a >> b >> p >> q;
	inv = qsm (p * q, MOD - 2);
	cout << get_ans (a, b) << endl;
}

signed main () {
	charming ();
	return 0;
}