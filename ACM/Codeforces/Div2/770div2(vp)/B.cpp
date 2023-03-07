#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
ll x, y;

void init () {}

void charming () {
	init ();
	cin >> n >> x >> y;
	ll sum = 0;
	for (int i = 1, a; i <= n; ++i) {
		cin >> a;
		sum += a;
	}
	if (((x + sum) & 1) == (y & 1)) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}