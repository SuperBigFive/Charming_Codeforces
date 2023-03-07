#include <bits/stdc++.h>
#define ll long long
#define itn ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> ans (n + 2);
	for (int i = 1; i <= n; i += 2) {
		ans[i] = (n + 1) / 2 - (i / 2);
		ans[i + 1] = 	n - (i - 1) / 2;
	}
	for (int i = 1; i <= n; ++i) 
	cout << ans[i] << " \n"[i == n];	
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}