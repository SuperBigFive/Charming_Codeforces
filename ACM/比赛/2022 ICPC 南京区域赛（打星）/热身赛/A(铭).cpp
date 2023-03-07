#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> a;
	int zeros = 0;
	for (int i = 1, b; i <= n; ++i) {
		cin >> b;
		if (!b) ++zeros;
		else a.emplace_back (b);
	}
	if (zeros > m) {
		cout << "Impossible" << endl;
		return;
	}
	if (n == m) {
		cout << "Richman" << endl;
		return;
	}
	int res = 0, mn = INT_MAX;
	for (int i = 0; i < m - zeros; ++i) 
	res += a[i];
	for (int i = m - zeros; i < a.size (); ++i) {
		mn = min (mn, a[i]);
	}
	res += mn - 1;
	cout << res << endl;
}

signed main () {
  cin >> t;
  while (t--) charming ();
  return 0;
}