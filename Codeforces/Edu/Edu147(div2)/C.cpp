#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;
int add[N];

void init () {}

void get_add () {
	add[1] = 1, add[2] = 2;
	for (int i = 3; i < N; ++i) add[i] = add[i / 2] + 1;
}

void charming () {
	init ();
	string s;
	cin >> s, n = s.size ();
	vector <int> exist (26);
	for (auto it : s) exist[it - 'a'] = 1;
	int ans = INT_MAX;
	for (int ch = 0; ch < 26; ++ch) if (exist[ch]) {
		int last = -1, nans = 0;
		for (int i = 0; i < n; ++i) if (s[i] - 'a' == ch) {
			nans = max (nans, add[i - last - 1]);
			last = i;
		}
		nans = max (nans, add[n - 1 - last]);
		ans = min (ans, nans);
	}
	cout << ans << endl;
}

signed main () {
	get_add ();
	cin >> t;
	while (t--) charming ();
	return 0;
}