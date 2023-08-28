#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, a, b;

void init () {}

void charming () {
	init ();
	cin >> n >> a >> b;
	if (n == 1 || a == n && b == n) cout << "Yes" << endl;
	else cout << (a + b + 2 <= n ? "Yes" : "No") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}