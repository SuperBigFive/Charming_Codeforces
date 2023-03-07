#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, m, s;

void init () {}

void charming () {
	init ();
	cin >> m >> s;
	vector <int> b (m);
	int mx = -1, cur, sum = 0;
	for (auto &it : b) {
		cin >> it;
		mx = max (mx, it);
		sum += it;
	}
	cur = mx * (mx + 1) / 2 - sum;
	while (cur < s) {
		cur += ++mx;
	}
	cout << (cur == s ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}