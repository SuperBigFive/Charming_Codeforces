#include <bits/stdc++.h>
#define ll  long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	multiset <int> s;
	for (int i = 1, a; i <= n; ++i) {
		cin >> a;
		s.insert (a);
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		while (s.size () && (*s.begin ()) < i) {
			auto it = s.find (*s.begin ());
			s.erase (it);
		}
		if (!s.size ()) break;
		auto it = s.find (*s.begin ());
		res += (*it) - i;
		s.erase (it);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}