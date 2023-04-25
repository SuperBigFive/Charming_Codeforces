#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, s;

void init () {}

void charming () {
	init ();
	cin >> n >> s;
	cout << s / (n * n) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}