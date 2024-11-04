#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	string s, t;
	cin >> s >> t;
	for (int i = 0; i + t.size () - 1 < s.size (); ++i) {
		string tmp = s.substr (i, t.size ());
		if (tmp == t) {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

signed main () {
	charming ();
	return 0;
}