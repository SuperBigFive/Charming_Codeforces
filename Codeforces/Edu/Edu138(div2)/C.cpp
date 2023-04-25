#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n;
vector <int> a;

void init () {a.clear ();}

bool check (int mx) {
	vector <int> b = a;
	int p = 1;
	for (int i = mx - 1; i < b.size (); ++i) {
		if (b[i] <= p) ++p;
	}
	return p > mx;
}

void charming () {
	init ();
	cin >> n;
	a.resize (n);
	for (auto &it : a) cin >> it;
	sort (a.begin (), a.end ());
	int res = n / 2 + 1;
	while (res > 0) {
		if (check (res)) {
			cout << res << endl;
			return;
		}
		--res;
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}