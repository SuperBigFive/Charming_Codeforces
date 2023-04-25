#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e2 + 5;

int n, l, r;

void init () {}

void charming () {
	init ();
	cin >> n >> l >> r;
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = (a[i] % (l + r)) / l;
		sum ^= a[i];
	}
	if (sum) cout << "First" << endl;
	else cout << "Second" << endl;
}

signed main () {
	charming ();
	return 0;
}