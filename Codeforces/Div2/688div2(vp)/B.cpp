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
	vector <int> a (n), b;
	for (auto &it : a) cin >> it;
	int sum = 0, res;
	for (int i = 0; i < n - 1; ++i) {
		b.emplace_back (abs (a[i] - a[i + 1]));
		sum += b.back ();
	}
	res = sum;
	for (int i = 1; i < n - 1; ++i)
	res = min (res, sum - (abs (a[i] - a[i - 1]) + 
	abs (a[i] - a[i + 1])) + abs (a[i - 1] - a[i + 1]));
	res = min (res, sum - abs (a[0] - a[1]));
	res = min (res, sum - abs (a[n - 1] - a[n - 2]));
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}