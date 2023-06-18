#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	unordered_set <int> us, nus, alls;
	for (auto &ai : a) {
		cin >> ai;
		for (auto &it : us) {
			int lcm = it * ai / __gcd (it, ai);
			if (lcm > N) continue;
			else nus.insert (lcm), alls.insert (lcm);
		}
		nus.insert (ai), alls.insert (ai);
		us = nus, nus.clear ();
	}
	int ans = 1;
	while (alls.count (ans)) ++ans;
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}