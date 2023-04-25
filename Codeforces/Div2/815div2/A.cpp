#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, m;

void init () {
	
}

void charming () {
	cin >> n >> m;
	if (n < m) swap (n, m);
	ll res;
	if (n == 1 && m == 1) {
		res = 0;
	}
	else if (m == 1) {
		res = n;
	}
	else res = n + m - 2 + m - 1 + 1;
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}