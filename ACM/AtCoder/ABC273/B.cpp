#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

void init () {}

void charming () {
	init ();
	int x, k;
	cin >> x >> k;
	int remain = 1;
	for (int i = 1; i <= k; ++i) {
		remain *= 10;
		x = x - x % remain + (x % remain >= remain / 2) * remain;
	}
	cout << x << endl;
}

signed main () {
	charming ();
	return 0;
}