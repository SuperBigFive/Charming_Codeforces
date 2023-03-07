#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s;
	char ch[3] = {'Y', 'e', 's'};
	int p;
	if (s[0] == 'Y') p = 0;
	else if (s[0] == 'e') p = 1;
	else if (s[0] == 's') p = 2;
	else {
		cout << "NO" << endl;
		return;
	}
	for (int i = 0; i < s.size (); ++i) {
		if (s[i] != ch[(i + p) % 3]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}