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
	vector <int> a (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];	
	if (a[n]) return void (cout << "NO" << endl);
	else cout << "YES" << endl;
	for (int i = n, j; i >= 1; i = j - 1) {
		j = i;
		if (a[i] == 0) cout << 0 << " ";
		else {
			while (j - 1 >= 1 && a[j - 1]) {
				cout << 0 << " ";
				--j;
			}
		 	cout << i - j + 1 << " ";
		}
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}