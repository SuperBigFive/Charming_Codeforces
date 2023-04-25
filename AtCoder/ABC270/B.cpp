#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

void init () {}

void charming () {
	int x, y, z;
	cin >> x >> y >> z;
	if (x < 0) x = -x, y = -y, z = -z;
	if (y > x || y < 0) cout << x << endl;
	else if (z < y && z > 0) cout << x << endl;
	else if (z < y && z < 0) cout << (abs (z) * 2 + x) << endl;
	else cout << -1 << endl;
}

signed main () {
	charming ();
	return 0;
}