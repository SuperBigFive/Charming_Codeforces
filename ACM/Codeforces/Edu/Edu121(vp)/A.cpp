#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t;

void init () {}

void charming () {
	init ();
	string s;
	cin >> s;
	vector <int> cnt (26);
	for (auto &it : s) ++cnt[it - 'a'];
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] == 2) {
			cout << (char) ('a' + i) << (char) ('a' + i);
		}
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] == 1)
		cout << (char) ('a' + i);
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}