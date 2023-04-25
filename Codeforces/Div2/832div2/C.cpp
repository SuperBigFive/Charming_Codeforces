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
	vector <int> arr (n);
	int mn = INT_MAX;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (i > 0) mn = min (mn, arr[i]);
	}
	cout << (arr[0] > mn ? "Alice" : "Bob") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}