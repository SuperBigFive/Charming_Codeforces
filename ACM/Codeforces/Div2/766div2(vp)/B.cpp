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
	pair <int, int> co[4];
	co[0] = make_pair (1, 1);
	co[1] = make_pair (1, m);
	co[2] = make_pair (n, 1);
	co[3] = make_pair (n, m);
	vector <int> dis;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			ll mx = -1;
			for (auto [x, y] : co) {
				mx = max (mx, abs (x - i) + abs (y - j));
			}
			dis.emplace_back (mx);
		}
	}
	sort (dis.begin (), dis.end ());
	for (auto &it : dis) cout << it << " ";
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}