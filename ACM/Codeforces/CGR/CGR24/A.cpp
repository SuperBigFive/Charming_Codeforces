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
	for (auto &it : a) {
		cin >> it;
	}
	cout << 1 << " " << n << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}