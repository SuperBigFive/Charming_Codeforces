#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	vector <vector <int> > dis (n), pre_1 (n), pre_2 (n);
	vector <vector <int> > type1 (n), type2 (n);
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		res = (res * 2) % mod;
		type1[i].resize (i), type2[i].resize (i);
		for (int j = i - 1, y; j >= 0; --j) {
			y = a[i] - a[j];
			int l = 0, r = dis[j].size () - 1, k = 0;
			while (l <= r) {
				int mid = l + r >> 1;
				if (dis[j][mid] <= y) l = mid + 1, k = mid;
				else r = mid - 1;
			}
			if (dis[j].size () && dis[j][k] <= y) {
				res = (res + pre_1[j][dis[j].size () - 1] - pre_1[j][k]) % mod;
				type1[i][i - j - 1] = (type1[i][i - j - 1] + pre_1[j][k] + pre_2[j][k]) % mod;
				type2[i][i - j - 1] = (type2[i][i - j - 1] + pre_1[j][dis[j].size () - 1] - pre_1[j][k]) % mod;
				type2[i][i - j - 1] = (type2[i][i - j - 1] + pre_2[j][dis[j].size () - 1] - pre_2[j][k]) % mod;
			} else if (dis[j].size ()) {
				res = (res + pre_1[j][dis[j].size () - 1]) % mod;
				type2[i][i - j - 1] = (type2[i][i - j - 1] + pre_1[j][dis[j].size () - 1]) % mod;
				type2[i][i - j - 1] = (type2[i][i - j - 1] + pre_2[j][dis[j].size () - 1]) % mod;
			}
			type2[i][i - j - 1] = (type2[i][i - j - 1] + 1) % mod;
			if (dis[i].size ()) {
				pre_1[i].emplace_back ((pre_1[i].back () + type1[i][i - j - 1]) % mod);
				pre_2[i].emplace_back ((pre_2[i].back () + type2[i][i - j - 1]) % mod);
			}
			else pre_1[i].emplace_back (type1[i][i - j - 1]), pre_2[i].emplace_back (type2[i][i - j - 1]);
			dis[i].emplace_back (y);
		}
		res = (res + i) % mod;
	}
	cout << ((res % mod) + mod) % mod << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	charming ();
	return 0;
}