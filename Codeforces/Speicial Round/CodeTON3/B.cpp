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
	string s;
	cin >> s;
	s = '#' + s;
	int cnt = 0, x = 0, y = 0;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] != s[i - 1]) cnt = 1;
		else ++cnt;
		res = max (res, cnt * cnt);
		if (s[i] == '1') ++x;
		else ++y;
	}
	cout << max (res, x * y) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}