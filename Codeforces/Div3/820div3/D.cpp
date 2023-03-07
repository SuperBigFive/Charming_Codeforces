#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 1e6 + 5;

int t, n;
int x[maxn], y[maxn];

void init () {}

void charming () {
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	for (int i = 1; i <= n; ++i) {
		cin >> y[i];
		y[i] -= x[i];
		if (y[i] >= 0) ++res;
	}
	sort (y + 1, y + 1 + n);
	int cnt = 0, p1 = 1, p2 = n;
	while (p1 < p2 && y[p1] < 0) {
		while (p1 < p2 && y[p1] + y[p2] < 0) ++p1;
		if (p1 < p2 && y[p1] < 0) ++cnt, ++p1, --p2;
		else break;
	}
	cout << ((res >> 1) + (cnt >> 1) + ((cnt & 1) && (res & 1))) << endl;
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}