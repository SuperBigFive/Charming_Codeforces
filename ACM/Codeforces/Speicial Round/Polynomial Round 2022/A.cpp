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
	int cnt = s[0] == '1';
	for (int i = 1; i < n; ++i) {
		if (s[i] == '0') cout << "+";
		else {
			++cnt;
			if (cnt & 1) cout << "+";
			else cout << "-";
		}
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}