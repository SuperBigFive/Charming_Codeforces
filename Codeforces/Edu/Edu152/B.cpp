#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	vector <pair <int, int> > a (n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first, a[i].first %= k;
		if (a[i].first == 0) a[i].first = k;
		a[i].second = i + 1;
	}
	sort (a.begin (), a.end (), [] (pair <int, int> &x,
	pair <int, int> &y) {
		if (x.first != y.first) return x.first > y.first;
		else return x.second < y.second;});
	for (int i = 0; i < n; ++i) cout << a[i].second << " \n"[i == n - 1];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}