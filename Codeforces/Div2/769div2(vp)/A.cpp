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
	string s;
	cin >> s;
	int cnt0 = 0, cnt1 = 0;
	for (auto &it : s) {
		if (it == '1') ++cnt1;
		else ++cnt0;
	}
	if (cnt0 > 1 || cnt1 > 1) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}