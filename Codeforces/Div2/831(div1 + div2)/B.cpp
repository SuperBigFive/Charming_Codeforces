#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n;

void init () {
	
}


void charming () {
	init ();
	cin >> n;
	vector <int> siz;
	ll res = 0, mx = 0;
	for (int i = 1, a, b; i <= n; ++i) {
		cin >> a >> b;
		mx = max ({mx, a, b});
		res += min (a, b);
	}
	res *= 2;
	res += 2 * mx;
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}