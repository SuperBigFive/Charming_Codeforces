#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming (int case_cnt) {
	init ();
	cin >> n;
	vector <int> ok (n + 5);
	vector <pair <int, int> > a (n + 5);
	for (int i = 1; i <= n; ++i) 
	cin >> a[i].first, a[i].second = i;
	sort (a.begin () + 1, a.begin () + 1 + n);
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		auto [val, id] = a[i];
		if (!ok[id - 1] && !ok[id + 1]) res ^= val, ok[id] = 1;
		else {
			int mx = max (ok[id - 1], ok[id + 1]) - 1;
			res ^= (val - (mx + 1)), ok[id] = mx + 1 + 1;
		}
	}
	cout << "Case " << case_cnt << ": " << (res & 1 ? "Alice" : "Bob") << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	for (int i = 1; i <= t; ++i) charming (i);
	return 0;
}