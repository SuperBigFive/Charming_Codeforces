#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
vector <int> prim[maxn];

void init () {}

void get_prim () {
	for (int i = 2, val; i < maxn; ++i) {
		val = i;
		for (int j = 2; j * j <= val; ++j) {
			while (!(val % j)) {
				val /= j;
				prim[i].emplace_back (j);
			}
		}
		if (val > 1) prim[i].emplace_back (val);
	}
}

void charming () {
	init ();
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	multiset <int> old_s, s;
	for (auto it : prim[a]) old_s.insert (it);
	for (auto it : prim[b]) old_s.insert (it);
	for (int i = a + 1, j, k; i <= c; ++i) {
		s = old_s;
		for (auto it : prim[i]) {
			if (s.count (it)) {
				s.erase (s.find (it));
			}
		}
		j = 1;
		for (auto it : s) j *= it;
		k = j * (b / j + 1);
		if (j * (b / j + 1) <= d) {
			cout << i << " " << k << endl;
			return;
		}
	}
	cout << -1 << " " << -1 << endl;
}

signed main () {
	get_prim ();
	cin >> t;
	while (t--) charming ();
	return 0;
}