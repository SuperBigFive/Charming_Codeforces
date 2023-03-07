#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	cin >> n;
	cout << (n - 6) / 3 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}