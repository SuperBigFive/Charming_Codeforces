#include <bits/stdc++.h>
#define ll long long
#define int ll
#define vi vector <int> 
#define pii pair <int, int> 
#define pb push_back 
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 5;

int t, n;

void init () {
	
}

void charming () {
	cin >> n;
	int x, y, x1, y1, x2, y2;
	x1 = INT_MAX, x2 = -INT_MAX, y1 = INT_MAX, y2 = -INT_MAX;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y;
		if (!x) {
			y1 = min (y1, y);
			y2 = max (y2, y);
		}
		else {
			x1 = min (x1, x);
			x2 = max (x2, x);
		}
	}
	if (x1 == INT_MAX) {
		x1 = x2 = 0;
	}
	if (y1 == INT_MAX) {
		y1 = y2 = 0;
	}
	int res = 0;
	if (x1 * x2 < 0) {
		res += abs (x1) + abs (x2);
	}
	else {
		res += max (abs (x1), abs (x2));
	}
	if (y1 * y2 < 0) {
		res += abs (y1) + abs (y2);
	}
	else {
		res += max (abs (y1), abs (y2));
	}
	cout << 2 * res << endl;
 }

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}