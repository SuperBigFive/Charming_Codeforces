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
	vector <int> arr (n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	cout << (arr[0] == 1 ? "Yes" : "No") << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}