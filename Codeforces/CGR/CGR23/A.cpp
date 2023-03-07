#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int t, n, k;
int a[maxn];

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	bool ok = false;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i]) ok = true;
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}