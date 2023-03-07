#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	string s1;
	cin >> s1;
	n = s1.length ();
	string s2 = s1;
	reverse (s2.begin (), s2.end ());
	cout << s1 << s2 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}