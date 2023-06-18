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
	string s1, s2, s3;
	cin >> s1 >> s2, s3 = s2, reverse (s3.begin (), s3.end ());
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; ++i) {
		ans1 += s1[i] != s2[i];
		ans2 += s1[i] != s3[i];
	}
	if (ans1 == 0) cout << 0 << endl;
	else if (ans1 == 1) cout << 1 << endl;
	else if (ans2 == 0) cout << 2 << endl; 
	else cout << min (ans1 * 2 - (ans1 & 1), ans2 * 2 - ((ans2 & 1) ^ 1)) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}