#include <bits/stdc++.h>
#define ll long long
#define int ll
#define eps 1e-8
using namespace std;
const int maxn = 2e6 + 5;

int q, n;
int x[maxn], t[maxn];

void init () {}

bool check (double pos) {
	double lc = -1, rc = -1;
	for (int i = 1; i <= n; ++i) {
		if (x[i] <= pos && lc < t[i] + pos - x[i])
		lc = (double)t[i] + pos - x[i];
		if (x[i] >= pos && rc < t[i] + x[i] - pos)
		rc = (double)t[i] + x[i] - pos;
	}
	return lc <= rc;
}


void charming () {
	init ();
	scanf ("%lld", &n);
	double l = INT_MAX, r = -1;
	for (int i = 1; i <= n; ++i) {
		scanf ("%lld", &x[i]);
		l = min ((ll) l, x[i]), r = max ((ll) r, x[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf ("%lld", &t[i]);
	}
	double res = l;
	while (l < r - eps) {
		double mid = (l + r) / 2;
		if (check (mid)) l = mid, res = mid;
		else r = mid;
	}
	printf ("%.6lf\n", res);
}

signed main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	scanf ("%lld", &q);
	while (q--) charming ();
	return 0;
}