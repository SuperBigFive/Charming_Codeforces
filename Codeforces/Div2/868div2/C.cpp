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
	vector <int> a (n + 5), p;
	for (int i = 1, tmp; i <= n; ++i) {
		cin >> a[i];
		tmp = a[i];
		for (int j = 2; j * j <= tmp; ++j) {
			while (tmp % j == 0) {
				p.emplace_back (j);
				tmp /= j;
			}
		}
		if (tmp > 1) p.emplace_back (tmp);
	}
	sort (p.begin (), p.end ());
	int ans = 0, remain = 0;
	for (int i = 0, j, id = 0; i < p.size (); i = j + 1) {
		j = i;
		while (j + 1 < p.size () && p[j + 1] == p[i]) ++j;
		ans += (j - i + 1) / 2, remain += (j - i + 1) % 2;
	}
	cout << ans + remain / 3 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}