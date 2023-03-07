#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int a, b, c;

void init () {}

void charming () {
	cin >> a >> b >> c;
	if (a < b) swap (a, b);
	if (a == b * 2 && !c) cout << 1 << endl;
	else cout << 0 << endl;
}

signed main () {
	charming ();
	return 0;
}