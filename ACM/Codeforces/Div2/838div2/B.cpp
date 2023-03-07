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
	vector <int> a (n);
	for (auto &it : a) cin >> it;
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		int POW2 = 1;
		while (POW2 < a[i]) POW2 <<= 1;
		cout << i + 1 << " " << POW2 - a[i] << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}