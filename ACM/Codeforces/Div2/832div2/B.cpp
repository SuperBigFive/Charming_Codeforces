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
	int res = (n + 1) / 2;
	vector <int> pos_a, pos_n;
	vector <pair <int ,int> > exc;
	for (int i = 1; i <= 3 * n; ++i) {
		if (i % 3 == 1) continue;
		else if (i % 3 == 2) pos_a.emplace_back (i);
		else pos_n.emplace_back (i);
	}
	for (int i = 0; i < res; ++i) {
		exc.emplace_back (make_pair (pos_a[i], pos_n[n - i - 1]));
	}
	cout << res << endl;
	for (auto [i, j] : exc) {
		cout << i << " " << j << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}