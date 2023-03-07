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
	for (int i = 0; i < n; ++i) cin >> arr[i];
	int res = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (arr[i] >  arr[i - 1] && arr[i] > arr[i + 1])
		arr[i + 1] = max (arr[i], arr[i + 2]), ++res;
	}
	cout << res << endl;
	for (int i = 0; i < n; ++i) 
	cout << arr[i] << " \n"[i == n - 1];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}