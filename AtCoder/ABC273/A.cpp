#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

void init () {}

void charming () {
	init ();
	int n;
	cin >> n;
	int f[15];
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
	f[i] = i * f[i - 1];
	cout << f[n] << endl;
}

signed main () {
	charming ();
	return 0;
}