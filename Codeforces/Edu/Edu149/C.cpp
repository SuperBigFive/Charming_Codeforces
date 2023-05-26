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
	for (int i = 0, j; i < n; i = j + 1) {
		j = i;
		if (s[i] == '?') {
			while (j + 1 < n && s[j + 1] == s[j]) ++j;
			if (j == n - 1 || (i > 0 && s[i - 1] == '1' && s[j + 1] == '1')) {
				for (int k = i; k <= j; ++k) s[k] = '1';
			}
			else for (int k = i; k <= j; ++k) s[k] = '0';
		}
	}
	for (int i = 0; i < n; ++i) cout << s[i];
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}