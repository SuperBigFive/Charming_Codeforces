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
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort (a.begin () + 1, a.begin () + 1 + n);
	int res = (a[1] != 0) + 1;
	for (int i = 1; i < n; ++i) if (a[i + 1] > i && a[i] < i) ++res;
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}