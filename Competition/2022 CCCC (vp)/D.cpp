#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int a, b;

void init () {}

void charming () {
	init ();
	cin >> a >> b;
	int ans = 1;
	for (int i = 1; i <= (a + b); ++i) ans *= i;
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}