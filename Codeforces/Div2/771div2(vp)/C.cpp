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
	vector <int> arr (n + 1), pos (n + 1);
	vector <int> mx_num (n + 1), mx_pos (n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		pos[arr[i]] = i;
		mx_num[i] = max (mx_num[i - 1], arr[i]);
	}
	for (int i = 1; i <= n; ++i) {
		mx_pos[i] = max (mx_pos[i - 1], pos[i]);	
	}
	int res = 0, p = 1, q, mx;
	while (p <= n) {
		q = mx_pos[arr[p]];
		mx = mx_num[q];
		if (mx <= arr[p]) p = q + 1, ++res;
		else p = pos[mx];
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}