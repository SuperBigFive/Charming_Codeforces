#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int n, a, b;

void init () {}

double get_cost (double k) {return (double) b * k + a / (pow (k + 1, 0.5));}

void charming () {
	init ();
	scanf ("%lld%lld", &a, &b);
	double l = 0, r = (double) LLONG_MAX * INT_MAX, k = 0;
	while (l <= r) {
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		if (get_cost (mid1) > get_cost (mid2)) l = mid1 + 1;
		else r = mid2 - 1, k = mid2;
		if (r - l <= 1e2) {
			double mn = get_cost (k);
			for (int i = l; i <= r; ++i) {
				double cur = get_cost (i);
				if (cur < mn) {
					mn = cur;
					k = i;
				}
			}
			break;
		}
	}
	printf ("%.10lf\n", get_cost (k));
}

signed main () {
	charming ();
	return 0;
}