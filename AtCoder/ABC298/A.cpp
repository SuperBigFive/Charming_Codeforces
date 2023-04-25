#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	bool ok1 = false, ok2 = true;
	string s;
	cin >> n >> s;
	for (auto it : s) {
		if (it == 'o') ok1 = true;
		else if (it == 'x') ok2 = false;
	}
	if (ok1 && ok2) cout << "Yes" << endl;
	else cout << "No" << endl;
}

signed main () {
	charming ();
	return 0;
}