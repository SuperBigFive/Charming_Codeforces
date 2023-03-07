#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
char ch;

void init () {}

void charming () {
	init ();
	cin >> n >> ch;
	string s;
	cin >> s;
	vector <int> green;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'g') {
			green.emplace_back (i);
			green.emplace_back (i + n);
		}
	}
	sort (green.begin (), green.end ());
	int res = -1;
	for (int i = 0, id; i < n; ++i) {
		if (s[i] == ch) {
			id = lower_bound (green.begin (), green.end (), i) - green.begin ();
			res = max (res, green[id] - i);
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}