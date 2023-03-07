#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int n;
ll cnt[maxn], res[maxn], pow2[maxn];
vector <int> fac[maxn];

void init () {}

/*void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	map <int, int> g;
	for (auto &it : a) {
		cin >> it;
		for (auto [GCD, num] : g) {
			(g[__gcd (GCD, it)] += num) %= mod;
		}
		++g[it];
	}
	cout << (((g[1] % mod) + mod) % mod) << endl;
}*/

void get_fac () {
	for (int i = 1; i < maxn; ++i) {
		for (int j = i; j < maxn; j += i) {
			fac[j].emplace_back (i);
		}
	}
}

void get_pow2 () {
	pow2[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		pow2[i] = (pow2[i - 1] * 2) % mod;
	}
}

void charming () {
	init ();
	cin >> n;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		for (auto it : fac[x]) ++cnt[it];
	}
	for (int i = maxn - 1; i >= 1; --i) {
		res[i] = pow2[cnt[i]] - 1;
		for (int j = i + i; j < maxn; j += i) {
			res[i] = (res[i] - res[j] + mod) % mod;
		}
	}
	cout << res[1] << endl;
}

signed main () {
	get_fac ();
	get_pow2 ();
	charming ();
	return 0;
}