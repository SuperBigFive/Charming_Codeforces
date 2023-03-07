#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;

int t, n;
string s;

void charming () {
	cin >> n;
	cin >> s;
	s = '#' + s;
	ll res = 0, cnt = 0;
	for (int i = n; i >= 1; --i) {
		if (s[i] == '0') ++cnt;
		else {
			if (cnt > 0) --cnt, res += i;
			else ++cnt;
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}