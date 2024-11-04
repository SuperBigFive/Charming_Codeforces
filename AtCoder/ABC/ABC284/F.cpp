#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e6 + 5;
const int P = 149;
const int mod = 13242352651234;

int n;
int hash1[N], hash2[N], POWP[N];

void init () {}

ll qsm(ll a, ll b) {
	ll res = 0;
  while (b) {
    if (b & 1) res = (res + a) % mod;
    a = (a << 1) % mod;
    b >>= 1;
  }
  return ((res % mod) + mod) % mod;
}

void get_hash (string &s) {
	POWP[0] = 1;
	for (int i = 1; i <= (n << 1); ++i) {
		hash1[i] = (hash1[i - 1] * P + s[i] - 'a') % mod;
		POWP[i] = (POWP[i - 1] * P) % mod;
	}
	for (int i = (n << 1); i >= 1; --i) {
		hash2[(n << 1) - i + 1] = (hash2[(n << 1) - i] * P + s[i] - 'a') % mod;
	}
}

ll cal (int l, int r, int st) {
	if (r < l) return mod + 1;
	int len = r - l + 1;
	ll res;
	if (st == 1) res = (hash1[r] - qsm (hash1[l - 1], POWP[len])) % mod;
	else res = (hash2[r] - qsm (hash2[l - 1], POWP[len])) % mod;
	res = (res + mod) % mod;
	return res;
}

void charming () {
	init ();	
	string s;
	cin >> n, cin >> s, s = '#' + s;
	get_hash (s);
	for (int i = 1, j = i + n - 1; j <= (n << 1); ++i, ++j) {
		int len1 = i - 1, len2 = (n << 1) - j;
		if (cal (1, i - 1, 1) != cal ((n << 1) - j + 1, (n << 1) - j + len1, 2)) continue;
		if (cal (j + 1, n << 1, 1) != cal ((n << 1) - j + len1 + 1, (n << 1) - i + 1, 2)) continue;
		for (int k = j; k >= i; --k) cout << s[k];
		cout << endl << i - 1 << endl;
		return;
	}
	cout << -1 << endl;
}

signed main () {
	charming ();
	return 0;
}