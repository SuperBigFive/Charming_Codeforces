#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
mt19937 rnd (random_device {}());

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;
	int p1 = 1, p2 = n;
	int d1 = k / 2, d2 = (k + 1) / 2;
	vector <int> res;
	while (p1 <= p2) {
		for (int i = 1; i <= d2 && p2 >= p1; ++i) {
			res.emplace_back (p2--);
		}
		for (int i = 1; i <= d1 && p2 >= p1; ++i) {
			res.emplace_back (p1++);
		}
	}
	for (int i = 0; i < res.size (); ++i) {
		cout << res[i] << " \n"[i == res.size () - 1];
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}