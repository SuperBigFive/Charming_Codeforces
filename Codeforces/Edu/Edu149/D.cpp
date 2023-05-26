#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for (auto ch : s) {
		if (ch == '(') ++cnt;
		else --cnt;
	}
	if (cnt) return void (cout << -1 << endl);
	for (int d = 0, left; d <= 1; ++d) {
		left = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') ++left;
			else if (left == 0) {
				left = -1;
				break;
			}
			else --left;
		}
		if (left == 0) {
			cout << 1 << endl;
			for (int i = 0; i < n; ++i) cout << 1 << " \n"[i == n - 1];
			return;
		}
		reverse (s.begin (), s.end ());
	}
	vector <pair <int, int> > stk;
	vector <int> col (n, 1);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') stk.emplace_back (make_pair (1, i));
		else if ((int) stk.size () && stk.back ().first == 1) stk.pop_back ();
		else stk.emplace_back (make_pair (0, i));
	}
	for (auto [st, id] : stk) col[id] = 2;
	cout << 2 << endl;
	for (int i = 0; i < n; ++i) cout << col[i] << " \n"[i == n - 1];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}