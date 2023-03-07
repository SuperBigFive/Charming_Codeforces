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
	vector <pair <int, int> > range (n);
	map <pair <int, int>, bool> vis;
	for (auto &it : range) {
		cin >> it.first >> it.second;
		vis[it] = true;
	}
	for (auto &it : range) {
		cout << it.first << " " << it.second << " ";
		if (it.first == it.second) {
			cout << it.second << endl;
			continue;
		}
		if (vis[make_pair (it.first, it.second - 1)]) {
			cout << it.second << endl;
			continue;
		}
		if (vis[make_pair (it.first + 1, it.second)]) {
			cout << it.first << endl;
			continue;
		}
		for (int i = it.first + 1; i <= it.second - 1; ++i) {
			if (vis[make_pair (it.first, i - 1)] &&
			vis[make_pair (i + 1, it.second)]) {
				cout << i << endl;
				break;
			}
		}
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}