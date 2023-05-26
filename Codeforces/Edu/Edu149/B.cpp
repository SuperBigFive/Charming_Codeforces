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
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0, j; i < n; i = j) {
		j = i;
		while (j < n && s[j] == s[i]) ++j;
		ans = max (ans, j - i);
	}
	cout << ans + 1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}