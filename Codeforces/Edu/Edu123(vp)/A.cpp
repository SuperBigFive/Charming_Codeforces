#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n;

void init () {}

void charming () {
	init ();	
	string s;
	cin >> s;
	map <int, bool> ok;
	for (int i = 0; i < 6; ++i) {
		if (s[i] <= 'z' && s[i] >= 'a') ok[(int) s[i] - 'a'] = true;
		else if (!ok[(int) s[i] - 'A']) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}