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
	int cnt = 0;
	vector <int> a (n + 5), pre (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pre[i] = pre[i - 1] + (a[i] == 2);
		cnt += (a[i] == 2);
	}
	if (cnt & 1) return void (cout << -1 << endl);
	for (int i = 1; i < n; ++i) if (pre[i] == cnt / 2) {
		cout << i << endl;
		return;
	}
	cout << -1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}