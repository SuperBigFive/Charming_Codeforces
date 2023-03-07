#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s;
	int id = -1, n = s.length ();
	for (int i = 0; i < n; ++i) if (s[i] == 'a') id = i + 1;
	cout << id << endl;
}

signed main () {
	charming ();
	return 0;
}