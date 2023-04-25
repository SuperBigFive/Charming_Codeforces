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
	vector <int> a (n), b (n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort (b.begin (), b.end ());
	int mx1 = b[n - 1], mx2 = b[n - 2];
	for (auto &it : a) {
		if (it != mx1) cout << it - mx1 << " ";
		else cout << mx1 - mx2 << " ";
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}