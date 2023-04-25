#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e6 + 5;

int t, n, m;
vector <int> prim;

void init () {}

void get_prim () {
	vector <int> vis (N);
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) prim.emplace_back (i);
		for (int j = 0; j < prim.size () && i * prim[j] < N; ++j) {
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0) break;
		}
	}
}

void charming () {
	init ();
	cin >> n >> m;
	vector <int> a (n);
	bool AllSame = true;
	int GCD = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		AllSame &= (a[i] == a[0]);
		GCD = __gcd (GCD, a[i]);
	}
	if (AllSame) return void (cout << 0 << endl);
	else if (GCD > 1) return void (cout << 1 << endl << GCD << endl);
	
	int l = 0, r = prim.size () - 1, mx = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (prim[mid] <= m) l = mid + 1, mx = mid;
		else r = mid - 1;
	}
	sort (a.begin (), a.end ());
	a.resize (unique (a.begin (), a.end ()) - a.begin ());
	n = a.size ();
	set <int> s;
	for (int i = 0; i < n; ++i) {
		for (auto it : prim) {
			if (it * it > a[i]) break;
			else if (a[i] % it == 0) {
				s.insert (it);
				while (a[i] % it == 0) a[i] /= it;
			}
		}
		if (a[i] > 1) s.insert (a[i]);
	}
	if (s.size () == mx + 1) cout << 2 << endl << 2 << endl << 3 << endl;
	else {
		for (auto it : prim) if (!s.count (it)) return void (cout << 1 << endl << it << endl);
	}
}

signed main () {
	cout << prim.size () << endl;
	cin >> t;
	while (t--) charming ();
	return 0;
}