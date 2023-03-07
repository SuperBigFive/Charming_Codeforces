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
	vector <int> a (n);
	int cnt = 0, res = 0;
	for (auto &it : a) cin >> it;
	int p1 = 0, p2 = n - 1;
	while (p1 <= n - 1 && a[p1] == 1) ++p1;
	while (p2 >= 0 && a[p2] == 1) --p2;
	if (p1 > n - 1 || p2 < 0) cout << 0 << endl;
	else cout << p2 - p1 + 2 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}