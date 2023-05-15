#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;	
	vector <int> a (n + 5);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = i, sum += i;
	}
	while (sum % n) ++a[1], ++sum;
	for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}