#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t;
string s;

void init () {}

void charming () {
	cin >> s;
	char be = s[0], en = s.back ();
	char mx = be, mn = en;
	if (mx < mn) swap (mx, mn);
	int cost = abs (be - en), step = 2;
	vector <int> pos[26];
	for (int i = 1; i < s.size () - 1; ++i) {
		if (s[i] >= mn && s[i] <= mx) ++step;
		pos[s[i] -'a'].emplace_back (i + 1);
	}
	cout << cost << ' ' << step << endl;
	cout << 1 << ' ';
	if (be > en) {
		for (int i = be - 'a'; i >= en - 'a'; --i) {
			for (auto it : pos[i]) cout << it << ' ';
		}
	}
	else {
		for (int i = be - 'a'; i <= en - 'a'; ++i) {
			for (auto it : pos[i]) cout << it << ' ';
		}
	}
	cout << s.size () << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}