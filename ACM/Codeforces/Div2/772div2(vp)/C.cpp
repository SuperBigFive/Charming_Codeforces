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
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (i > 0 && arr[i] < arr[i - 1]) ok = false;
	}
	if (ok) {
		cout << "0" << endl;
		return;
	}
	if (arr[n - 2] > arr[n - 1] || arr[n - 1] < 0) {
		cout << -1 << endl;
		return;
	}
	cout << n - 2 << endl;
	for (int i = 1; i <= n - 2; ++i) {
		cout << i << " " << n - 1 << " " << n << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}