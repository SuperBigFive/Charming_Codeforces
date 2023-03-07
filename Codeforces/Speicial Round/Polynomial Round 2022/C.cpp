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
	cin >> s, s = '#' + s;
	vector <int> l0 (n + 1), l1 (n + 1);
	for (int i = 1; i < n; ++i) {
		l0[i] = l0[i - 1], l1[i] = l1[i - 1];
		if (s[i] == '0') l0[i] = i;
		else l1[i] = i;
	}
	for (int i = 1; i < n; ++i) {
		if (s[i] == '0') cout << l1[i] + 1 << " \n"[i == n - 1];
		else cout << l0[i] + 1 << " \n"[i == n - 1];
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}