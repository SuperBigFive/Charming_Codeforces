#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m, rb, cb, rd, cd;

void init () {}

void charming () {
	init ();
	cin >> n >> m >> rb >> cb >> rd >> cd;
	cout << min (rb <= rd ? rd - rb : n * 2 - rb - rd,
	cb <= cd ? cd - cb : m * 2 - cb - cd) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}