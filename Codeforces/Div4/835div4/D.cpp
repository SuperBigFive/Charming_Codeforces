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
	vector <int> a(n + 2);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	a[0] = a[n + 1] = INT_MAX;
	int cnt = 0;
	for (int i = 1, j; i <= n; i = j + 1) {
		j = i;
		while (a[j + 1] == a[i]) ++j;
		if (a[i - 1] > a[i] && a[j + 1] > a[j]) ++cnt;
	}
	cout << (cnt == 1 ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}