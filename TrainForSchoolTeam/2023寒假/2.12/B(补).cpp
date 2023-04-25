#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s, s = '#' + s;
	int siz = s.size () - 1;
	int sum = 0;
	for (int i = 1, cnt = 0; i <= siz; ++i) {
		cnt += (s[i] == '1');
		if (s[i] == '0') sum += cnt;
	}
	cout << (sum % 3 ? "Alice" : "Bob") << endl;
}

signed main () {
	charming ();
	return 0;
}