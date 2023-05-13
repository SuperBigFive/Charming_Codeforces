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
	cin >> s, n = s.size ();
	vector <int> vis (26);
	int cnt = 0;
	for (int i = 0; i < n / 2; ++i) {
		if (vis[s[i] - 'a']) continue;
		else vis[s[i] - 'a'] = 1, ++cnt;
	}
	if (cnt > 1) cout << "YES" << endl;
	else cout << "NO" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}