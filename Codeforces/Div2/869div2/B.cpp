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
	if (n == 1) cout << 1 << endl;
	else if (n & 1) cout << -1 << endl;
	else {
		for (int i = 1; i <= n / 2; ++i) 
		cout << i * 2 << " " << i * 2 - 1 << " ";
		cout << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}