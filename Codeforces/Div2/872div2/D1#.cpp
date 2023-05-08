#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int t, n, k;

void init () {}

ll qsm (ll x, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) ans = (ans * x) % MOD;
		p >>= 1, x = (x * x) % MOD;
	}
	return ans;
}

void charming () {
	init ();
	cin >> n >> k;
	vector <vector <int> > G (n + 5);
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].emplace_back (v);
		G[v].emplace_back (u);
	}
	ll p = 0, q;
	vector <int> siz (n + 5);
	if (k == 1) return void (cout << 1 << endl);
	else if (k == 2) {
		q = n * (n - 1) / 2;
		q = qsm (q % MOD, MOD - 2);
		
		auto DFS = [&] (auto && me, int f, int u) -> void {
			siz[u] = 1;
			for (auto &v : G[u]) {
				if (v == f) continue;
				me (me, u, v);
				p = (p + siz[u] * siz[v]) % MOD;
				siz[u] += siz[v];
			}
			p = (p + (n - siz[u]) * siz[u]) % MOD;
		};
		
		DFS (DFS, 0, 1);
	}
	else {
		q = n * (n - 1) * (n - 2) / 6;
		q = qsm (q % MOD, MOD - 2);
		
		auto DFS = [&] (auto && me, int f, int u) -> void {
			siz[u] = 1;
			ll np = 0, cnt = 0;
			for (auto &v : G[u]) {
				if (v == f) continue;
				++cnt;
				me (me, u, v);
				if (cnt >= 3) p = (p + np * siz[v]) % MOD;
				np = (np + (siz[u] - 1) * siz[v]) % MOD;
				siz[u] += siz[v];
			}
			int f_siz = n - siz[u] + 1;
			np = (np * f_siz) % MOD;
			p = (p + np) % MOD;
			p = (p + (siz[u] - 1) * (f_siz - 1)) % MOD;
		};
		
		DFS (DFS, 0, 1);
	}
	ll ans = (p % MOD) * q % MOD;
	ans = ((ans % MOD) + MOD) % MOD;
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}
