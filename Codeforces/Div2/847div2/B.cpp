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
	vector <pair <int, int> > p;
	p.emplace_back (make_pair (0, 1));
	for (int i = 2, cnt; i * i <= n; ++i) {
		if (n % i == 0) {
			cnt = 0;
			while (n % i == 0) {
				n /= i;
				++cnt;
			}
			p.emplace_back (make_pair (cnt, i));
		}
	}
	if (n > 1) p.emplace_back (make_pair (1, n));
	ll res = 0, prod = 1;
	for (int i = 1; i < p.size (); ++i) prod *= p[i].second;
	sort (p.begin (), p.end ());
	for (int i = 1; i < p.size (); ++i) {
		res += prod * (p[i].first - p[i - 1].first);
		prod /= p[i].second;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}