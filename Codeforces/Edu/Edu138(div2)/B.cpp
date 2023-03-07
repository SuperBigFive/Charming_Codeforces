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
	int res = 0;
	for (auto &it : a) cin >> it, res += it;
	for (auto &it : b) cin >> it, res += it;
	int mx = 0;
	for (auto &it : b) mx = max (mx, it);
	res -= mx;
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}