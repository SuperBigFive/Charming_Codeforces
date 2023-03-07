#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
int a[maxn];
string s;

void init () {}

void charming () {
	init ();
	cin >> n >> s;
	s = '#' + s;
	int res = 0, be = 0;
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (s[i] != '1') ok = false;
		if (ok) {
			be = i;
			res += a[i];
		}
	}
	++be;
	for (int i = be, j, val; i <= n; i = j) {
		j = i + 1, val = 0;
		int mn = INT_MAX;
		while (s[j] == '1') val += a[j], mn = min (mn, a[j++]);
		if (a[i] > mn) val += a[i] - mn;
		res += val;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}