#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, k;
ll fac[N], inv[N];

ll fpow (ll x, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) ans = (ans * x) % MOD;
		p >>= 1, x = (x * x) % MOD;
	}
	return ans;
}

ll C (ll n, ll m) {
	if (n < m) return 0;
	else return (((fac[n] * inv[m]) % MOD) * inv[n - m]) % MOD;
}

void Get_Fac () {
	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = (fac[i - 1] * i) % MOD;
		inv[i] = fpow (fac[i], MOD - 2);
	}
}

int DFS (int &p, int f, int u, vector <vector <int> > &G) {
	int usiz = 1, vsiz;
	for (auto &v : G[u]) {
		if (v == f) continue;
		vsiz = DFS (p, u, v, G);
		usiz += vsiz;
		p = (p + C (n - vsiz, k >> 1) * C (vsiz, k >> 1)) % MOD;
	}
	return usiz;
}

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <vector <int> > G (n + 5);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].emplace_back (v);
		G[v].emplace_back (u);
	}
	if (k & 1) return void (cout << 1 << endl);
	ll p = 0, q = fpow (C (n, k), MOD - 2);
	DFS (p, 0, 1, G);
	ll ans = p * q % MOD;
	ans = ((ans % MOD + 1) + MOD) % MOD;
	cout << ans << endl;
}

signed main () {
	Get_Fac ();
	charming ();
	return 0;
}