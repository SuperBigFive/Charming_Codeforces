#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 5e5 + 5;

int t, n, m, p;

void init () {}

double qsm (double num, int d) {
	double res = 1;
	while (d) {
		if (d & 1) res = res * num;
		d >>= 1;
		num = num * num;
	}
	return res;
}

double f (int k) {return (n * k + m) / (1 - qsm ((1 - p * 0.0001), k));}

void charming () {
	init ();	
	scanf ("%lld%lld%lld", &n, &m, &p);
	if (p == 10000) {cout << n + m << endl; return;}
	ll l = 1, r = 1e9;
	double res = LLONG_MAX;
	while (r - l >= 100) {
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		if (f (mid1) < f (mid2)) r = mid2;
		else l = mid1;
	}
	for (int i = l; i <= r; ++i) res = min (res, f (i));
	printf ("%.10lf\n", res);
}

signed main () {
	scanf ("%lld", &t);
	while (t--) charming ();
	return 0;
}