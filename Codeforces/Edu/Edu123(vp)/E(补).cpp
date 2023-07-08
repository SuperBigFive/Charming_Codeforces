#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n, siz;

void init () {}

void charming () {
	init ();	
	string s;
	cin >> n;
	cin >> s;
	int cntr = 0, cntd = 0;
	for (auto it : s) {
		if (it == 'R') ++cntr;
		else ++cntd;
	}
	int dr = n - cntr - 1, dd = n - cntd - 1;
	if (!cntr || !cntd) {
		cout << n << endl;
		return;
	}
	siz = s.length ();
	ll res = siz + 1;
	s.push_back (s.back ());
	int st = (s[0] == 'R');
	bool ok = false;
	for (int i = 0; i < siz; ++i) {
		if (s[i] != s[i + 1]) {
			res += (st ? dr : dd);
			st ^= 1;
			ok = true;
		}
		else if (ok) res += (st ? dd : dr);
	}
	res += ((st ? dd : dr) + 1) * (st ? dr : dd);
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}