#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e4 + 5;

int t, n;
vector <int> prim;

void init () {}

void get_prim () {
	for (int i = 2; i < N; ++i) {
		bool ok = true;
		for (int j = 2; j * j <= i; ++j) {
			if (!(i % j)) {
				ok = false;
				break;
			}
		}
		if (ok) prim.emplace_back (i);
	}
}

void charming () {
	init ();
	cin >> n;	
	vector <int> a (n);
	for (auto &it : a) cin >> it;
	sort (a.begin (), a.end ());
	if (unique (a.begin (), a.end ()) - a.begin () < n) {
		cout << "NO" << endl;
		return;
	}
	vector <vector <int> > num (prim.size ());
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int diff = a[j] - a[i];
			for (int k = 0; k < prim.size (); ++k) {
				if (diff % prim[k]) continue;
				num[k].emplace_back ((-a[i]) % prim[k]);
			}
		}
	}
	for (int i = 0, m; i < prim.size (); ++i) {
		sort (num[i].begin (), num[i].end ());
		m = unique (num[i].begin (), num[i].end ()) - num[i].begin ();
		if (m >= prim[i]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

signed main () {
	get_prim ();
	cin >> t;
	while (t--) charming ();
	return 0;
}