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
	vector <int> a (n + 5), b (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int l = -1, r = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		if (b[i] != a[i]) {
			if (l == -1) l = i;
			r = i;
		}
	}
	while (l - 1 >= 1 && a[l - 1] <= b[l]) --l;
	while (r + 1 <= n && a[r + 1] >= b[r]) ++r;
	cout << l << " " << r << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}