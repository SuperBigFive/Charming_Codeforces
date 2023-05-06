#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

void init () {}

void charming () {
	init ();
	string s1, s2;
	cin >> s1 >> s2;
	
	auto get_str = [] (string s) -> string {
		int siz = s.size ();
		string ans;
		for (int i = 1; i < siz; ++i) {
			if ((s[i] - '0') % 2 == (s[i - 1] - '0') % 2) {
				ans += max (s[i], s[i - 1]);
			}
		}
		return ans;
	};
	
	string ns1 = get_str (s1), ns2 = get_str (s2);
	cout << ns1 << endl;
	if (ns1 != ns2) cout << ns2 << endl;
}

signed main () {
	charming ();
	return 0;
}