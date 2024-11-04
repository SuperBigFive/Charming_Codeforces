#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s;
	if (s == "ACE" || s == "BDF" || s == "CEG" || s == "DFA"
	|| s == "EGB" || s == "FAC" || s == "GBD") cout << "Yes" << endl;
	else cout << "No" << endl;
}

signed main () {
	charming ();
	return 0;
}