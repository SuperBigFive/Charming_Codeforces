#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;	
	int mn = 1, cnt = 0;
	while ((mn << 1) < n) mn <<= 1;
	for (int i = n - 1; i >= 0; --i) {
		if (i >= mn) cout << i << " ";
		else cout << (cnt++) << " ";
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}