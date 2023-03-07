#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <pair <int, int> > city (n);
	int res = 0, l, r;
	for (auto &it : city) {
		cin >> it.first >> it.second;
		res += it.second;
	}
	sort (city.begin (), city.end ());
	l = city[0].first, r = l + city[0].second;
	for (int i = 0; i < n; ++i) {
		if (city[i].first <= r) {
			l = max (l, city[i].first);
			r = max (r, city[i].first + city[i].second);
		}
		else {
			res += city[i].first - r;
			l = city[i].first;
			r = l + city[i].second;
		}
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}