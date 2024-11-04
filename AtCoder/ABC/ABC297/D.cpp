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
	int ans = 0;
	while (a != b) {
		if (a < b) swap (a, b);
		if (a % b == 0) {
			ans += a / b - 1;
			break;
		}
		int d = a / b;
		ans += d;
		a = a % b;
	}
	cout << ans << endl;
}

signed main () {
	charming ();
	return 0;
}