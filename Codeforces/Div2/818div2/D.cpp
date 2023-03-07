#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int n, k;
int pow2[maxn], inv[maxn];

void init () {}

int ex_gcd (int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int GCD = ex_gcd (b, a % b, x, y);
	int tmp = y;
	y = x - (a / b) * y;
	x = tmp;
	return GCD;
}
	
void get_pow2 () {
	pow2[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		pow2[i] = (pow2[i - 1] << 1) % mod;
	}
}

void get_inv () {
	for (int i = 1, x, y; i < maxn; ++i) {
		x = y = 0;
		ex_gcd (i, mod, x, y);
		inv[i] = x;
	}
}

void charming () {
	cin >> n >> k;	
	if (k >= n) {
		cout << pow2[n] % mod << endl;
		return;
	}
	int sum = 1, tmp = 1;
	for (int i = 1; i <= k; ++i) {
		tmp = ((tmp * (n - i + 1)) % mod) * inv[i] % mod;
		tmp = (tmp % mod + mod) % mod;
		sum = (sum + tmp) % mod;
	}
	sum = (sum % mod + mod) % mod;
	cout << sum << endl;
}

signed main () {
	get_pow2 ();
	get_inv ();
	charming ();
	return 0;
}