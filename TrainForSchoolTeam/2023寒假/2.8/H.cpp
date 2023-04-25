#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming (int case_cnt) {
	init ();
	string s1, s2, r;
	cin >> s1 >> s2, n = s1.size ();
	s1 = '#' + s1, s2 = '#' + s2;
	vector <int> suf (n + 5);
	for (int i = n; i >= 1; --i)
	suf[i] = suf[i + 1] + (s1[i] != s2[i]);
	int delta = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 26; ++j) {
			char ch = 'a' + j;
			if (abs (delta + (s1[i] == ch) - (s2[i] == ch)) <= suf[i + 1]) {
				r += ch, delta += (s1[i] == ch) - (s2[i] == ch);
				break;
			}
		}
	}
	cout << "Case " << case_cnt << ": " << r << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	for (int i = 1; i <= t; ++i) charming (i);
	return 0;
}