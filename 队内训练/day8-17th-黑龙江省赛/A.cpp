#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e5 + 5;

int t, p, q, res, delta;
int a, b, n, m, h;

void init () {}

int f (int k) {return max (res - k * delta, q + k * b);}

void charming () {
	init ();
	cin >> a >> b >> n >> m >> h;
	p = n / b;
	if (p * (h - a) >= m - 1) {
		cout << n + 1 << endl;
		return;
	}
	res = n + m - p * (h - a);
	q = p * b, delta = h - b;
	if (delta <= 0) {
		cout << res << endl;
		return;
	}
	int l = 0, r = (res - n) / delta, mn = INT_MAX;
	while (l <= r) {
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		if (f (mid1) < f(mid2)) r = mid2 - 1;
		else l = mid1 + 1;
		if (r - l <= 100) {
			for (int i = l; i <= r; ++i)
			mn = min (mn, f(i));
		}
	}
	cout << mn << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}