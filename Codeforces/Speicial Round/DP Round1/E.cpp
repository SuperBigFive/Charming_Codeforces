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
	vector <pair <int, int> > a (n);
	for (auto &it : a) cin >> it.first;
	for (auto &it : a) cin >> it.second;
	sort (a.begin (), a.end (), [] (pair <int, int> &x,
	pair <int, int> &y) {return x.first * y.second > y.first * x.second;});
	int remain = 0, res = 0, id = 0;
	while (id < n && remain < m) {
		remain += a[id].first;
		res += a[id].second;
		++id;
	}
	if (remain < m) return (void) (cout << -1 << endl);
	--id;
	if (a[id].second == 2) {
		for (int i = id - 1; i >= 0; --i) {
			if (a[i].second == 1) {
				if (remain - a[i].first >= m) {
					cout << res - 1 << endl;
					return;
				}
				break;
			}
		}
		for (int i = id + 1; i < n; ++i) {
			if (a[i].second == 1) {
				if (remain - a[id].first + a[i].first >= m) {
					cout << res - 1 << endl;
					return;
				}
			}
		}
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}