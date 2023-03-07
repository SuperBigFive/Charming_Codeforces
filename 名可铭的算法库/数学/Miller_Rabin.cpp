#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;

ll n;

ll slow_mul (ll times, ll num, ll mod) {
	ll res = 0;
	num %= mod;
	while (times) {
		if (times & 1) res = (res + num) % mod; 
		times >>= 1;
		num = (num + num) % mod;
	}
	return res;
}

ll binpow (ll pow, ll num, ll mod) {
	ll res = 1;
	num %= mod;
	while (pow) {
		if (pow & 1) res = slow_mul (num, res, mod) % mod;
		pow >>= 1;
		num = slow_mul (num, num, mod) % mod;
	}
	return res;
}

bool Miller_Rabin (ll num) {
	if (num == 2) return true;
	if (!(num & 1) || num == 1) return false;
	ll mm = num - 1, tt, a, x, y;
	while (!(mm & 1)) mm >>= 1, ++tt;
	srand (time (NULL));
	for (int i = 1; i <= 5; ++i) {
		a = rand () % (num - 1) + 1;
		if (binpow (num - 1, a, num) != 1) return false;
		x = binpow (mm, a, num);
		for (int j = 1; j <= tt; ++j) {
			y = slow_mul (x, x, num);
			if (y == 1 && x != 1 && x != num - 1) return false;
			x = y;
		}
		if(x != 1 && x != num - 1) return false;
	}
	return true;
}

void charming () {
	cin >> n;
	if (Miller_Rabin (n)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}
