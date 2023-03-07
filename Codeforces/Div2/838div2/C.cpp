#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;
const int mod = 998244353;

int t, n;

void init () {}
	
void charming () {
	init ();
	cin >> n;
	string s;
	cin >> s;
	s = '#' + s;
	int cnt = 0;
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] != s[i - 1]) cnt = 1;
		res = (res + cnt) % mod;
		cnt = (cnt * 2) % mod;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}