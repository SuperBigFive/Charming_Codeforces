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
	int mx = 0;
	for (auto &it : s)
	mx = max (mx, (int)it - 'a' + 1);
	cout << mx << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}