#include <bits/stdc++.h>
#define ll long long
#define itn ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	string s;
	cin >> s;
	int cnt1 = 0, cnt2 = 0;
	for (auto it : s) {
		if (it == 'Q') ++cnt1;
		else ++cnt2;
		cnt2 = min (cnt1, cnt2);
	}
	cout << (cnt1 <= cnt2 ? "Yes" : "No") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}