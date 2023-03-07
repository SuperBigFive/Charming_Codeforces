#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n;
string s, t, u;

void init () {}

void charming () {
	init ();
	cin >> n;
	cin >> s >> t;
	int diff = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) ++diff;
	}
	if (diff & 1) {
		cout << -1 << endl;
		return;
	}
	int cnts = 0, cntt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) {
			if (s[i] == '0') {
				if (cntt < diff / 2) ++cntt, u += '0';
				else ++cnts, u += '1';
			}
			else {
				if (cnts < diff / 2) ++cnts, u += '0';
				else ++cntt, u += '1';
			}
		}
		else u += '0';
	}
	cout << u << endl;
}

signed main () {
	charming ();
	return 0;
}