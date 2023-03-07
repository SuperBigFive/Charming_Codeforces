#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	vector <int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort (a.begin (), a.end ());
	cout << a[1] << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}