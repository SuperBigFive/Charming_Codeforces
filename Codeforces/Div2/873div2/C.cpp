#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;	
	vector <int> a (n + 5), b (n + 5);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	sort (a.begin () + 1, a.begin () + 1 + n);
	sort (b.begin () + 1, b.begin () + 1 + n);
	ll ans = 1;
	vector <int> c;
	for (int i = 1; i <= n; ++i) c.emplace_back (a[i]);
	if (a[1] <= b[1]) {
		cout << 0 << endl;
		return;
	}
	for (int i = 2, id, j; i <= n; ++i) {
		if (a[i] <= b[i]) {
			cout << 0 << endl;
			return;
		}
		id = upper_bound (c.begin (), c.end (), b[i]) - c.begin ();
		ans = (ans + (i - id - 1) * ans) % MOD;
	}
	cout << ans << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}