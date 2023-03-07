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
	vector <pair <int, int> > a (n), b;
	for (int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i;
	b = a;
	sort (b.begin (), b.end ());
	if (m < b[0].first) {
		cout << n + 1 << endl;
		return;
	}
	int wins = 0, sum = 0;
	set <int> s;
	for (int i = 0; i < n && sum <= m; ++i) {
		if (sum + b[i].first <= m) {
			sum += b[i].first;
			++wins, s.insert (b[i].second);
		}
		else break;
	}
	if (s.count (wins) || wins >= n) {
		cout << max (1ll, n - wins) << endl;
		return;
	}
	if (sum - b[wins - 1].first + a[wins].first <= m) {
		cout << max (1ll, n - wins) << endl;
	}
	else cout << max (1ll, n - wins + 1) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}