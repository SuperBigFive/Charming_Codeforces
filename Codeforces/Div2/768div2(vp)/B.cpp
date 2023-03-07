#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;		
	vector <int> a (n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int p = n, res = 0;
	while (true) {
		int q = p;
		while (q >= 1 && a[q] == a[n]) --q;	
		if (q < 1) break;
		++q;
		for (int i = max (1ll, q - (n - q + 1)); i < q; ++i) {
			a[i] = a[p];
		}
		++res;
		p = max (1ll, q - (n - q + 1));
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}