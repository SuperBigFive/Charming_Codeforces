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
	vector <int> a (n);
	int mx = 0, sum = 0;
	for (auto &it : a) 
	cin >> it, mx = max (mx, it), sum += it;
	if (sum == 0) cout << 0 << endl;
	else if (sum - mx + 1 >= mx) cout << 1 << endl;
	else cout << 1 + mx - (sum - mx + 1) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}