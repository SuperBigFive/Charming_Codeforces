#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int a[maxn];

void init () {}

void charming () {
	init ();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n > 8) {
		cout << 0 << endl;
		return;
	}
	else cout << 6 * (10 - n) * (10 - n - 1) / 2 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}