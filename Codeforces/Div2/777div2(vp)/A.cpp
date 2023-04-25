#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	int cnt = (n % 3) != 1, sum = 0, nxt;
		while (sum < n) {
			nxt = 1 + ((cnt++) & 1);
			sum += nxt;
			cout << nxt;
		}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}