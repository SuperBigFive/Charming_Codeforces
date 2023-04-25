#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s;
	if (s[0] == '0') return void (cout << 0 << endl);
	int cnt = 0;
	for (auto it : s) if (it == '?') ++cnt;
	if (s[0] == '?') cout << (int) pow (10, cnt) - pow (10, cnt - 1) << endl;
	else cout << (int) pow (10, cnt) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}