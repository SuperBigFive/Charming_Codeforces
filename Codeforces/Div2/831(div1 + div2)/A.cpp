#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e5 + 5;

int t, n;

void init () {
	
}

set <int> prim;

void charming () {
	init ();
	cin >> n;
	for (auto it : prim) {
		if (!prim.count (it + n)) {
			cout << it << endl;
			return;
		}
	}
}

signed main () {
	for (int i = 2; i < maxn; ++i) {
		bool ok = true;
		for (int j = 2; j * j <= i; ++j) {
			if (!(i % j)) {
				ok = false;
				break;
			}
		}
		if (ok) prim.insert (i);
	}
	cin >> t;
	while (t--) charming ();
	return 0;
}