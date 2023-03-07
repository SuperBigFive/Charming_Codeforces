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
	vector <int> cnt (10);
	vector <int> lmx (10, INT_MAX), rmx (10), umx (10, INT_MAX), dmx (10);
	vector <array <pair <int, int>, 10> > r (n + 5), c (n + 5);
	vector <vector <int> > mp (n + 5, vector <int> (n + 5));
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s, s = '#' + s;
		for (int j = 1; j <= n; ++j) {
			mp[i][j] = s[j] - '0';
			++cnt[mp[i][j]];
			lmx[mp[i][j]] = min (lmx[mp[i][j]], j);
			rmx[mp[i][j]] = max (rmx[mp[i][j]], j);
			umx[mp[i][j]] = min (umx[mp[i][j]], i);
			dmx[mp[i][j]] = max (dmx[mp[i][j]], i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!r[i][mp[i][j]].first) r[i][mp[i][j]].first = j;
			else r[i][mp[i][j]].second = j;
		}
	}
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (!c[j][mp[i][j]].first) c[j][mp[i][j]].first = i;
			else c[j][mp[i][j]].second = i;
		}
	}
	for (int i = 0, res; i < 10; ++i) {
		if (cnt[i] < 2) {cout << 0 << " "; continue;}
		res = 0;
		for (int j = 1; j <= n; ++j) {
			res = max (res, (r[j][i].second - r[j][i].first) * (n - j));
			if (r[j][i].first) res = max (res, max (n - r[j][i].first, r[j][i].first - 1)
			* max (abs (dmx[i] - j), abs (umx[i] - j)));
			if (r[j][i].second) res = max (res, max (n - r[j][i].second, r[j][i].second - 1)
			* max (abs (dmx[i] - j), abs (umx[i] - j)));
			res = max (res, (c[j][i].second - c[j][i].first) * (n - j));
			if (c[j][i].first) res = max (res, max (n - c[j][i].first, c[j][i].first - 1) 
			* max (abs (rmx[i] - j), abs (lmx[i] - j)));
			if (c[j][i].second) res = max (res, max (n - c[j][i].second, c[j][i].second - 1) 
			* max (abs (rmx[i] - j), abs (lmx[i] - j)));
		}
		cout << res << " ";
	}
	cout << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}