#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;

int t, n, m, k, q;
int x[maxn], y[maxn];

void init () {}

ll qsm (ll num, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = (res * num) % mod;
		p >>= 1;
		num = (num * num) % mod;
	}
	return res;
}

void charming () {
	init ();	
	cin >> n >> m >> k >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> x[i] >> y[i];
	}
	if (m == 1 || n == 1) {
		cout << k << endl;
		return;
	}
	int ok = 0;
	map <int, bool> visx;
	map <int, bool> visy;
	for (int i = q; i >= 1; --i) {
		bool chex = (!visx.count (x[i]) && visy.size () < m);
		bool chey = (!visy.count (y[i]) && visx.size () < n);
		if (chex || chey) ++ok;
		visx[x[i]] = true;
		visy[y[i]] = true;
	}
	ll res = qsm (k, ok);
	res = ((res % mod) + mod) % mod;
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}