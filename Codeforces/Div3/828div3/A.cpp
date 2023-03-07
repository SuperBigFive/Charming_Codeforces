#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> id[55], a (n);
	string  s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		id[a[i]].emplace_back (i);
	}
	cin >> s;
	bool ok = true;
	for (int i = 1; i <= 50; ++i) {
		if (!id[i].size ()) continue;
		char ch = s[id[i][0]];
		for (auto it : id[i]) {
			if (s[it] != ch) ok = false;
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}