#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <int> a (n);
	int c = 1;
	for (auto &it : a) {
		cin >> it;
		if (it == c) ++c;
	}
	if (c == n + 1) cout << 0 << endl;
	else cout << (n - c) / k + 1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}
	