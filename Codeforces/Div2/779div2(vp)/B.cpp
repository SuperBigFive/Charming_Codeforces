#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define fir first
#define se second
using namespace std;
const int maxn = 2e7 + 5;
const int mod = 998244353;

int t, n;
ll fac[maxn];

void init () {}

void get_fac () {
	fac[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
}

void charming () {
	init ();
	cin >> n;
	if (n & 1) {
		cout << 0 << endl;
		return;
	}
	ll res = fac[n >> 1] * fac[n >> 1] % mod;
	cout << res << endl;
}

signed main () {
	get_fac ();
	cin >> t;
	while (t--) charming ();
	return 0;
}