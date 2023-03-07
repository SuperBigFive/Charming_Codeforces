#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 3e5 + 5;

int t, n;

void init () {}


void charming () {
	init ();
	string s1, s2;
	cin >> s1 >> s2; 
	if (s1.back () < s2.back ()) cout << ">" << endl;
	else if (s1.back () > s2.back ()) cout << "<" << endl;
	else if (s1 == s2) cout << "=" << endl;
	else if (s1.back () == 'S' && s1.size () > s2.size ()) cout << "<" << endl;
	else if (s1.back () == 'S' && s1.size () < s2.size ()) cout << ">" << endl;
	else if (s1.back () == 'L' && s1.size () > s2.size ()) cout << ">" << endl;
	else cout << "<" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}