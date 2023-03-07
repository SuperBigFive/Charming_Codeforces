#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, a, b, c;

void init () {}

void charming () {
	init ();
	cin >> a >> b >> c;
	int cost1 = abs (a - 1);
	int cost2 = abs (b - c) + abs (c - 1);
	if (cost1 < cost2) cout << 1 << endl;
	else if (cost1 > cost2) cout << 2 << endl;
	else cout << 3 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}