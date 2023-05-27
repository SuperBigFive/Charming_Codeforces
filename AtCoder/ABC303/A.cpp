#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size (); ++i) {
		if (s1[i] == 'o') s1[i] = '0';
		if (s1[i] == 'l') s1[i] = '1';
	}
	for (int i = 0; i < s2.size (); ++i) {
		if (s2[i] == 'o') s2[i] = '0';
		if (s2[i] == 'l') s2[i] = '1';
	}
	cout << ((s1 == s2) ? "Yes" : "No") << endl;
}

signed main () {
	//freopen ("data.in", "r", stdin);
	charming ();
	return 0;
}
