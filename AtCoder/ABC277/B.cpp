#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	map <string, int> mp, valid;
	vector <string> vecs;
	cin >> n;
	string s;
	bool ok = true;
	char chk1[4] = {'H', 'D', 'C', 'S'};
	char chk2[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			string t;
			t += chk1[i], t += chk2[j];
			valid[t] = 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		if (mp.count (s) || !valid.count (s)) ok = false;
		mp[s] = 1;
	}
	cout << (ok ? "Yes" : "No") << endl;
}

signed main () {
	charming ();
	return 0;
}