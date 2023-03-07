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
	ll prod = 1;
	for (auto &it : a) {
		cin >> it;
		prod *= it;
	}
	cout << (prod + n - 1) * 2022 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}