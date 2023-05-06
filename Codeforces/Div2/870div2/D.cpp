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
	vector <int> a (n + 5), b (n + 5), c (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i] - (n - i + 1);
		c[i] = a[i] - i;
	}
	set <pair <int, int> > mx;
	vector <pair <int, int> > ans (n + 5);
	for (int i = 1; i <= n; ++i) {
		if (i > 1) {
			auto [val, id] = *mx.rbegin ();
			ans[i].first = a[id] - (i - id + 1);
		}
		mx.insert (make_pair (b[i], i));
	}
	mx.clear ();
	for (int i = n; i >= 1; --i) {
		if (i < n) {
			auto [val, id] = *mx.rbegin ();
			ans[i].second = a[id] - (id - i);	
		}
		mx.insert (make_pair (c[i], i));
	}
	int res = 0;
	for (int i = 2; i < n; ++i) res = max (res, a[i] + ans[i].first + ans[i].second);
	cout << res + 1 << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}