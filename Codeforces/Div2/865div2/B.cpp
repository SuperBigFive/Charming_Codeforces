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
	int p = 2 * n, q = 2;
	vector <vector <int> > ans (2, vector <int> (n + 1));
	for (int i = 1; i <= n; ++i) {
		if (i & 1) ans[0][i] = p, p -= 2;
		else ans[0][i] = q, q += 2;
	}
	p = n + 1, q = 1;
	for (int i = 1; i <= n; ++i) {
		if (i & 1) ans[1][i] = q, q += 2;
		else ans[1][i] = p, p += 2;
	}
	for (int i = 1; i <= n; ++i)
	cout << ans[0][i] << " \n"[i == n];
	for (int i = 1; i <= n; ++i)
	cout << ans[1][i] << " \n"[i == n];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}