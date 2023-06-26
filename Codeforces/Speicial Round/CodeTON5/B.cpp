#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e2 + 5;

int t, n, x;

void init () {}

void charming () {
	init ();
	cin >> n >> x;
	array <vector <int>, 3> book, ok;
	for (int i = 0; i < 3; ++i) {
		book[i].resize (n), ok[i].resize (n);
		for (int j = 0; j < n; ++j) {
			cin >> book[i][j];
			if ((book[i][j] & x) == book[i][j]) ok[i][j] = 1;
		}
	}
	int y = 0;
	for (int i = 0, j; i < 3; ++i) {
		j = 0;
		while (j < n && ok[i][j]) {
			y |= book[i][j];
			++j;
		}
	}
	if (x == y) cout << "Yes" << endl;
	else cout << "No" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}