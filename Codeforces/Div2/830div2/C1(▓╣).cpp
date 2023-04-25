#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, q;

void init () {}

void charming () {
	init ();
	cin >> n >> q;
	vector <int> a (n + 5);
	vector <int> Sum (n + 5), Xor (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		Sum[i] = Sum[i - 1] + a[i];
		Xor[i] = Xor[i - 1] ^ a[i];
	}
	int Mx = Sum[n] - Xor[n];
	int l, r;
	cin >> l >> r;
	for (int i = 1, j; i <= n; ++i) {
		bool ok = false;
		for (j = min (n, i + r - l); j >= i; --j) {
			if ((Sum[j] - Sum[i - 1]) - (Xor[j] ^ Xor[i - 1]) < Mx) {
				break;
			}
			ok = true;
		}
		if (ok && j - i < r - l + 1) l = i, r = j + 1;
	}
	cout << l << " " << r << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}