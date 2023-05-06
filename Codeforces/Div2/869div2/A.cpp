#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <string> s (n + 5);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		if (s[i] == s[1]) ++ans;
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}