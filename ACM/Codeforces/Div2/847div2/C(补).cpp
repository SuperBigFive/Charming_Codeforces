#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, s;

void init () {}

void charming () {
	init ();
	cin >> n >> s;
	vector <int> a (n + 5);
	vector <pair <int, int> > seq (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i == 1) seq[i] = make_pair (0, 0);
		else if (i == n) seq[i] = make_pair (a[i], a[i]);
		else {
			seq[i].first = max (0ll, min (s, a[i] - s));
			seq[i].second = min (a[i], max (s, a[i] - s));
		}
	}
	int last1 = 0, last2 = 0;
	for (int i = 2, nlast1, nlast2; i <= n; ++i) {
		nlast1 = min (last1 + (a[i - 1] - seq[i - 1].first) * seq[i].first,
		last2 + (a[i - 1] - seq[i - 1].second) * seq[i].first);
		nlast2 = min (last1 + (a[i - 1] - seq[i - 1].first) * seq[i].second,
		last2 + (a[i - 1] - seq[i - 1].second) * seq[i].second);
		last1 = nlast1, last2 = nlast2;
	}
	cout << last2 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}