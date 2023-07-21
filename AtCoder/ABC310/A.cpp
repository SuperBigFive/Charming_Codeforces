#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int n, p, q;

void init () {}

void charming () {
	init ();
	cin >> n >> p >> q;
	vector <int> d (n);
	for (auto &i : d) cin >> i;
	cout << min (p, q + *min_element (d.begin (), d.end ())) << endl;
}

signed main () {
	charming ();
	return 0;
}