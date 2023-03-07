#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, c0, c1, h;

void init () {}

void charming () {
	init ();
	cin >> n >> c0 >> c1 >> h;
	int cnt0 = 0, cnt1 = 0;
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') ++cnt0;
		else ++cnt1;
	}
	cout << min ({cnt0 * c0 + cnt1 * c1, h * cnt0 + c1 * n,
	h * cnt1 + c0 * n}) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}