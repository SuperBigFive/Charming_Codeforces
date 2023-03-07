#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <string> s (n + 1), t (n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] = '0' + s[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
		t[i] = '0' + t[i];
	}
	map <string, int> cnts, cntt;
	for (int i = 1; i <= m; ++i) {
		string s1, t1;
		for (int j = 1; j <= n; ++j) {
			if (s[j][i] == '#') s1.push_back ('#');
			else s1.push_back ('.');
			if (t[j][i] == '#') t1.push_back ('#');
			else t1.push_back ('.');
		}
		cnts[s1]++;
		cntt[t1]++;
	}
	for (auto &it : cnts) {
		if (cntt[it.first] != it.second) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

signed main () {
	charming ();
	return 0;
}