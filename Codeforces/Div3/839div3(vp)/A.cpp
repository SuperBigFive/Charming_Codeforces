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
	cin >> s;
	int a = s[0] - '0', b = s[2] - '0';
	cout << a + b << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}