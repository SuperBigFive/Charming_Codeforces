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
	vector <int> a (n + 1);
	int fi = 0, co = 0, se = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != i && a[i] != n - i + 1) ++co;
		else if (a[i] != i) ++fi;
		else ++se;
	}
	if (fi + co <= se) {
		cout << "First" << endl;
	}
	else if (se + co < fi) {
		cout << "Second" << endl;
	}
	else cout << "Tie" << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}