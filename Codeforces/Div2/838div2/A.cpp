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
	vector <int> a (n), b;
	ll res = INT_MAX, sum = 0;
	for (auto &it : a) {
		cin >> it;
		sum += it;
		int cnt = 0, tmp = it;
		if (it & 1) {
			while (tmp & 1) {
				++cnt;
				tmp >>= 1;
			}
			res = min (res, cnt);
		}
		else {
			while (!(tmp & 1)) {
				++cnt;
				tmp >>= 1;
			}
			res = min (res, cnt);
		}
	}
	if (sum & 1) cout << res << endl;
	else cout << 0 << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}