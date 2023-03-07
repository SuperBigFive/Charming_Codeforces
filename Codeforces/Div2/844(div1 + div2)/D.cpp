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
	vector <int> a (n);
	map <int, vector <pair <int, int> > > edge;
	for (auto &it : a) cin >> it;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int diff = a[j] - a[i];
			for (int k = 1; k * k <= diff; ++k) {
				if (diff % k == 0) {
					if (((diff / k) & 1) ^ (k & 1)) continue;
					int k1 = (diff / k - k) / 2;
					int k2 = (diff / k + k) / 2;
					if (k1 * k1 < a[i] || k2 * k2 < a[j]) continue;
					int x = k1 * k1 - a[i];
					if (x >= 0 && x <= 1e18) edge[x].emplace_back (make_pair (i, j));
				}
			}
		}
	}
	auto find = [&] (auto && me, int x, vector <int> &pre) -> int {
		if (x == pre[x]) return x;
		return pre[x] = me (me, pre[x], pre);
	};
	int res = 1;
	for (auto &x : edge) {
		vector <int> pre (n), siz (n);
		for (int i = 0; i < n; ++i) pre[i] = i, siz[i] = 1;
		for (auto &[u, v] : x.second) {
			int fu = find (find, u, pre);
			int fv = find (find, v, pre);
			if (fu == fv) continue;
			siz[fu] += siz[fv];
			pre[fv] = fu;
			res = max (res, siz[fu]);
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}