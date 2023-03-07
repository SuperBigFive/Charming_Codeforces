#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

string s, t;

void init () {}

void charming () {
	cin >> s >> t;
	if (s.size () > t.size ()) {
		cout << "No" << endl;
		return;
	}
	for (int i = 0; i < s.size (); ++i) {
		if (s[i] != t[i]) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

signed main () {
	charming ();
	return 0;
}