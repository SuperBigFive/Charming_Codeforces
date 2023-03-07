#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();	
	string s;
	cin >> s;
	n = s.length ();
	vector <int> nxt (n);
	nxt[n - 1] = n;
	for (int i = n - 2, last = n + 1; i >= 0; --i) {
		if (s[i] != s[i + 1]) nxt[i] = last = i + 1;
		else nxt[i] = last;
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res = max (res, (2 * n - nxt[i] - i));
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}