#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> a (n);
	set <int> s;
	for (auto &it : a) {
		cin >> it;
		s.insert (it);
	}
	if (s.size () == 1) {
		cout << "NO" << endl;
		return;
	}
	sort (a.begin (), a.end ());
	cout << "YES" << endl;
	cout << a[n - 1] << " " << a[0] << " ";
	for (int i = 1; i < n - 1; ++i) cout << a[i] << " \n"[i == n - 2];
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}