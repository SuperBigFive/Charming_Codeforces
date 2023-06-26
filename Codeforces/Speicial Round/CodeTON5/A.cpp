#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e2 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> a (n), b (m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int j = 0; j < m; ++j) cin >> b[j];
	sort (a.begin (), a.end ());
	sort (b.begin (), b.end ());
	int p1 = n - 1, p2 = m - 1;
	while (p1 >= 0 && p2 >= 0) {
		int tmp1 = a[p1], tmp2 = b[p2];
		a[p1] -= tmp2, b[p2] -= tmp1;
		if (a[p1] <= 0) --p1;
		if (b[p2] <= 0) --p2;
	}
	if (p1 < 0 && p2 < 0) cout << "Draw" << endl;
	else if (p1 < 0) cout << "Tenzing" << endl;
	else cout << "Tsondu" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}