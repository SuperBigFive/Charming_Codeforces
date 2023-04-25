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
	vector <int> arr (n + 1);
	int idl = -1, idr = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (idl == -1 && arr[i] != i) idl = i;
		if (arr[i] == idl) idr = i;
	}
	if (idl != -1) {
		for (int i = idl, j = idr; i <= j; ++i, --j)
		swap (arr[i], arr[j]);
	}
	for (int i = 1; i <= n; ++i) cout << arr[i] << " \n"[i == n];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}