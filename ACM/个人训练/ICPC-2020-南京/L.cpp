#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e5 + 5;

int t, n, m;

void init () {}

void charming () {
	init ();	
	cin >> n >> m;
	vector <pair <int, int> > a (n + m + 1);
	map <int, int> mp;
	for (int i = 0; i < n + m; ++i) {
		cin >> a[i].first;
		if (i < n) a[i].second = 1;
		else a[i].second = 0, ++mp[a[i].first];
	}
	a[n + m].first = INT_MAX;
	sort (a.begin (), a.end (), [] (pair <int, int> &x, 
	pair <int, int> &y) {return x.first < y.first;});
	int res = 0, cnt = 0;
	for (auto &[pos, st] : a) {
		if (st == 1 && !mp.count (pos)) ++cnt;
		else {
			res = max (res, cnt);
			cnt = 0;
		}
	}
	if (!res) cout << "Impossible" << endl;
	else cout << res << endl;
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> t;
	while (t--) charming ();
	return 0;
}