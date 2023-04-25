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
	int id = -1;
	for (int i = 0; i < n; ++i) {
		if (i < n - 1 && s[i] == 'R' && s[i + 1] == 'L') {
			cout << 0 << endl;
			return;
		}
		if (s[i] == 'L' && s[i + 1] == 'R') id = i + 1;
	}
	if (id != -1) cout << id << endl;
	else cout << -1 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}