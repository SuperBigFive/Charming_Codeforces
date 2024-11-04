#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int maxn = 2e6 + 5;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n), b (n), ans (n);
	for (int i = 0; i < n; ++i)
	cin >> a[i], b[i] = a[i];
	sort (b.begin (), b.end ());
	int m = unique (b.begin (), b.end ()) - b.begin ();
	for (int i = 0, id; i < n; ++i) {
		id = upper_bound (b.begin (), b.begin () + m, a[i]) - b.begin ();
		++ans[m - id];
	}
	for (auto it : ans) {
		cout << it << endl;
	}
}

signed main () {
	charming ();
	return 0;
}