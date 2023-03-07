#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

string s;

void init () {}

void charming () {
	init ();	
	cin >> s;
	string t = "edgnb";
	int n = s.length ();
	int res = 0;
	for (int i = 0; i + 5 - 1 < n; ++i) {
		if (s.substr (i, 5) == t) ++res;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}