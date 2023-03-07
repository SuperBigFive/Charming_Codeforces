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
	vector <int> a (n);
	for (auto &it : a) cin >> it;
	int mx = a[0], mn = a[0];
	for (auto &it : a) {
		mx |= it;
		mn &= it;
	}
	cout << mx - mn << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}