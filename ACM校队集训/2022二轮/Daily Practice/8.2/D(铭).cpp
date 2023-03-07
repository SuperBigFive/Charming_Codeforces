#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int>
#define pii pair <int, int> 
#define pip pair <int, pii>
#define pb push_back 
#define fi first
#define se second
#define inl inline
using namespace std;
const int maxn = 2e5 + 5;
int read () {
	char ch = getchar ();
	bool flag = true;
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = false;
		ch = getchar ();
	}
	int k = ch - '0';
	while (ch = getchar (), ch <= '9' && ch >= '0') {
		k = (k << 1) + (k << 3);
		k += (ch - '0');
	}
	if (flag) return k;
	return -k;
}

int t, p, q;

void init () {
	
}

void charming () {
	init ();
	p = read (), q = read ();
	int GCD = __gcd (p, q);
	p /= GCD, q /= GCD;
	if (p < 2 * q) {
		printf ("0 0\n");
		return;
	}
	int fac1 = p * p - 4 * q * q;
	int fac2 = sqrt (fac1);
	if (fac2 * fac2 != fac1) {
		printf ("0 0\n");
		return;
	}
	if (p - fac2 <= 0) {
		printf ("0 0\n");
		return;
	}
	ll k = (p - fac2) * 2, a = p - fac2;
	ll b = k * q / a;
	GCD = __gcd (a, b);
	a = a / GCD, b = b / GCD;
	if (a <= 1e9 && a > 0 && b <= 1e9 && b > 0) printf ("%lld %lld\n", a, b);
	else printf ("0 0\n");
}

signed main () {
	t = read ();
	while (t--) charming ();
	return 0;
}