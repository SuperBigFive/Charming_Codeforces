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
	vector <int> a (n + 5), vis (n + 5);
	int more = -1, cnt = 0, ok = 1;
	for (int i = 1, delta; i < n; ++i) {
		cin >> a[i], delta = a[i] - a[i - 1];
		if (delta > n) {
			if (more == -1) more = delta;
			else ok = 0;
		}
		else if (vis[delta]) {
			if (more == -1) more = delta;
			else ok = 0;
		}
		else vis[delta] = 1, ++cnt;
	}
	if (!ok) cout << "No" << endl;
	else if (more == -1) cout << "Yes" << endl;
	else if (cnt != n - 2) cout << "No" << endl;
	else {
		int sum = 0;
		for (int i = 1; i <= n; ++i) if (!vis[i]) sum += i;
		if (sum != more) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}