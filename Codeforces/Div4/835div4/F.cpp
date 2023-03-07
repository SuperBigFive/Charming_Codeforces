#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, n, c, d;

void init () {}

bool check (int k, vector <int> &a) {
	if (!k) return d * a[0] >= c;
	int day = 1, p = 0;
	ll sum = 0;
	while (day <= d) {
		if (day % (k + 1) == 1) p = 0;
		if (p < n) sum += a[p++];
		++day;
	}
	return sum >= c;
}

void charming () {
	init ();
	cin >> n >> c >> d;
	vector <ll> a (n);
	for (auto &it : a) cin >> it;
	sort (a.begin (), a.end (), greater <int> ());
	ll sum = 0;
	for (int i = 0; i < min (n, d); ++i) {
		sum += a[i];
	}
	if (sum >= c) {
		cout << "Infinity" << endl;
		return;
	}
	if (d * a[0] < c) {
		cout << "Impossible" << endl;
		return;
	}
	int l = 0, r = 1e9, k = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid, a)) l = mid + 1, k = mid;
		else r = mid - 1;
	}
	cout << k << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}