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
	vector <int> a (n), pre (n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		pre[i] = pre[max (0ll, i - 1)] + a[i];
	}
	int res = 0, tagl = 0, tagr = 0;
	priority_queue <int> pql, pqr;
	for (int i = m; i < n; ++i) {
		if (a[i] < 0) pqr.push (-a[i]);
		while (pre[i] + tagr < pre[m - 1]) {
			++res, tagr += pqr.top () * 2, pqr.pop ();
		}
	}
	for (int i = m - 1; i >= 0; --i) {
		while (pre[i] < pre[m - 1] - tagl) {
			++res, tagl += pql.top () * 2, pql.pop ();
		}
		if (a[i] > 0) pql.push (a[i]);
	}
	cout << res << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}