#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m, p;
ll fac[maxn], inv[maxn];

void init () {}

void get_fac () {
	fac[0] = 1;
	for (int i = 1; i <= p; ++i) {
		fac[i] = (fac[i - 1] * i) % p;
	}	
}

void get_inv () {
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= p; ++i) {
		inv[i] = (p - (ll)(p / i) * inv[p % i] % p) % p;
	}
	for (int i = 2; i <= p; ++i) {
		inv[i] = (ll) inv[i - 1] * inv[i] % p;
	}
}

ll lucas (int x, int y) {
	if (x < y) return 0;
	if (x < p) return ((fac[x] * inv[y] % p) * inv[x - y]) % p;
	return lucas (x / p, y / p) * lucas (x % p, y % p) % p;
}

void charming () {
	cin >> n >> m >> p;
	n += m;
	get_fac ();
	get_inv ();
	cout << lucas (n, m) << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}