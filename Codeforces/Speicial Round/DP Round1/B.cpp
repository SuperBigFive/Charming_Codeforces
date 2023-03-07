#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	cin >> n >> k;
	vector <int> ans (n), mx (n + 1);
	vector <pair <int, int> > point (n);
	for (auto &it : point) cin >> it.first;
	for (auto &it : point) cin >> it.second;
	sort (point.begin (), point.end ());
	for (int i = 0, j = 0, p = 0; i < n; i = p) {
		p = i;
		while (p < n && point[p].first == point[i].first) ++p;
		while (j < n && point[j].first <= point[i].first + k) ++j;
		for (int q = i; q < p; ++q) ans[q] = j - i;
	}
	for (int i = n - 1; i >= 0; --i) mx[i] = max (mx[i + 1], ans[i]);
	int res = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && point[j].first <= point[i].first + k) ++j;
		res = max (res, ans[i] + mx[j]);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}