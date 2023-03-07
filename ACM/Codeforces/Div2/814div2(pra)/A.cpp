#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define eb emplace_back 
#define pii pair <int, int> 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, a, b, c, d, n, m;

void init () {
	
}

void charming () {
	init ();
	cin >> a >> b >> c >> d;
	m = b * c;
	n = a * d;
	if (!a && !c) {
		cout << 0 << endl;
		return;
	}
	if (!a || !c) {
		cout << 1 << endl;
		return;
	}
	int GCD = __gcd (m, n);
	m /= GCD;
	n /= GCD;
	int res = 0;
	if (m > 1) ++res;
	if (n > 1) ++res;
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}