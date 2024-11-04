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
	vector <string> s (n);
	for (auto &it : s) cin >> it;
	
	auto Check = [&] (int x, int y) -> bool {
		bool ok = true;
		for (int i = x; i < x + 3; ++i) {
			for (int j = y; j < y + 3; ++j) {
				if (s[i][j] == '.') ok = false;
			}
		}
		for (int j = y; j <= y + 3; ++j) {
			if (s[x + 3][j] == '#') ok = false;
		}
		for (int i = x; i <= x + 3; ++i) {
			if (s[i][y + 3] == '#') ok = false;
		}
		for (int i = x + 6; i < x + 9; ++i) {
			for (int j = y + 6; j < y + 9; ++j) {
				if (s[i][j] == '.') ok = false;
			}
		}
		for (int j = y + 5; j < y + 9; ++j) {
			if (s[x + 5][j] == '#') ok = false;
		}
		for (int i = x + 5; i < x + 9; ++i) {
			if (s[i][y + 5] == '#') ok = false;
		}
		return ok;
	};
	
	for (int i = 0; i + 8 < n; ++i) {
		for (int j = 0; j + 8 < m; ++j) {
			if (Check (i, j)) cout << i + 1 << " " << j + 1 << endl;
		}
	}
}

signed main () {
	charming ();
	return 0;
}