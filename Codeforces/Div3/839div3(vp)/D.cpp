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
	int l = 1, r = 1e8;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] > a[i + 1]) {
			l = max (l, (a[i] + a[i + 1] - 1) / 2 + 1);
		}
		else if (a[i] < a[i + 1]) {
			r = min (r, (a[i] + a[i + 1]) / 2);	
		}
	}
	cout << (r >= l ? (r + l) / 2 : -1) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}