#include <bits/stdc++.h>
#define ll long long
#define int ll 
using namespace std;
const int N = 2e5 + 5;

int n;

void init () {

}

void charming () {
	init ();
	vector <pair <int, int> > FRe;
	cin >> n;
	FRe.emplace_back (make_pair (1, 8));
	FRe.emplace_back (make_pair (6, 18));
	FRe.emplace_back (make_pair (28, 28));
	FRe.emplace_back (make_pair (88, 58));
	FRe.emplace_back (make_pair (198, 128));
	FRe.emplace_back (make_pair (328, 198));
	FRe.emplace_back (make_pair (648, 388));
	int res = n * 10;
	int mx = 0;
	for (int i = 0; i < (1 << 7); ++i) {
		int price = 0, extra = 0;
		for (int j = 0; j < 7; ++j) {
			if ((i >> j) & 1) {
				price += FRe[j].first;
				extra += FRe[j].second;
			}
		}
		if (price <= n) mx = max (mx, extra);
	}
	cout << res + mx << endl;
}

signed main () {
	charming ();
	return 0;
}