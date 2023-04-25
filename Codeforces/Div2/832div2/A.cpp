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
	vector <int> arr (n);
	int sum1 = 0, sum2 = 0;
	for (auto &it : arr) {
		cin >> it;
		if (it < 0) sum2 += it;
		else sum1 += it;
	}
	cout << abs (sum2 + sum1) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}