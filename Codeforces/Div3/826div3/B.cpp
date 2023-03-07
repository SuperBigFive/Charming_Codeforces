#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

int t, n;

void init () {}


void charming () {
	init ();
	cin >> n;
	if (n == 3) {
		cout << -1 << endl;
		return;
	}
	cout << n << " " << n - 1 << " ";
	for (int i = 3; i <= n; ++i) cout << i - 2 << " \n" [i == n];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}