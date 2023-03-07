#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;
mt19937 rnd (random_device {} ());

int t, n;

void init () {}

void charming () {
	init ();
	t = 1;
	cout << t << endl;
	while (t--) {
		n = 1000;
		cout << n << endl;
		for (int i = 1; i <= n; ++i) {
			cout << rnd () % 100 + 1 << " \n"[i == n];
		}
	}
}

signed main () {
	charming ();
	return 0;
}