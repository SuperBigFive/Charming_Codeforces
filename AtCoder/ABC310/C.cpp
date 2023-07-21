#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	string s, revs;
	set <string> vis;
	for (int i = 1; i <= n; ++i) {
		cin >> s, revs = s;
		reverse (revs.begin (), revs.end ());
		if (vis.count (s) || vis.count (revs)) continue;
		else vis.insert (s);
	}
	cout << (int) vis.size () << endl;
}

signed main () {
	charming ();
	return 0;
}