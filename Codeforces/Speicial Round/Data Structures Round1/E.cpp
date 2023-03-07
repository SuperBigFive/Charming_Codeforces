#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n + 5), sum (n + 5);
	vector <pair <int, int> > last;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int res = 1;
	last.emplace_back (make_pair (n + 1, LLONG_MAX));
	for (int i = 1, p, mx; i * (i + 1) / 2 <= n; ++i) {
		p = -1, mx = -1;
		vector <pair <int, int> > nxt;
		for (int j = n - i + 1, k = j + i - 1; j >= 1; --j, --k) {
			while (p + 1 < last.size () && last[p + 1].first > k)
			mx = max (mx, last[++p].second);
			if (mx > sum[k] - sum[j - 1]) 
			nxt.emplace_back (make_pair (j, sum[k] - sum[j - 1]));
		}
		last = nxt;
		if (last.size ()) res = i;
		else break;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}