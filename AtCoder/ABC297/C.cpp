#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <string> s (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] = '#' + s[i];
		for (int j = 1; j < m; ++j) {
			if (s[i][j] == s[i][j + 1] && s[i][j] == 'T')
			s[i][j] = 'P', s[i][j + 1] = 'C';
		}
		for (int j= 1; j <= m; ++j)
		cout << s[i][j];
		cout << endl;
	}
}

signed main () {
	charming ();
	return 0;
}