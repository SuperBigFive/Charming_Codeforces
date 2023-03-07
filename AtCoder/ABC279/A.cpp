#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s;
	int res = 0;
	for (auto &it : s) {
		if (it == 'v') res += 1;
		else res += 2;	
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}