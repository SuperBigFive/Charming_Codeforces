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
	int res = 0;
	vector <int> arr (n + 1);
	for (int i = 1; i <= n; ++i) 
	cin >> arr[i], res |= arr[i];
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}