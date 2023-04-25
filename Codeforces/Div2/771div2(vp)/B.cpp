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
	vector <int> arr (n), odd (1, -1), even (1, 0);
	bool ok = true;
	for (auto &it : arr) {
		cin >> it;
		if (it & 1) {
			if (it < odd.back ()) ok = false;
			odd.emplace_back (it);
		}
		else {
			if (it < even.back ()) ok = false;
			even.emplace_back (it);
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}