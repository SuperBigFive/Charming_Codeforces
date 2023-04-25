#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	string s;
	cin >> n >> s;
	int cnt = 1, tag = s[0] - '0', win = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] - '0' == tag) ++cnt;
		else if (cnt) --cnt, win ^= 1;
		else cnt = 1, tag ^= 1;
	}
	if (win) cout << "Ramos" << endl;
	else cout << "Zlatan" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}