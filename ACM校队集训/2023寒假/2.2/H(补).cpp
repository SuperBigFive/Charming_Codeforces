#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int n;

void init () {}

void charming () {
	init ();
	cin >> n;
	vector <int> h (n + 5), pre (n + 5), id (n + 5);
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
		pre[i] = max (pre[i - 1], h[i]);
		if (h[i] > pre[i - 1]) id[i] = i;
		else id[i] = id[i - 1];
	}
	int res = 1;
	vector <int> pos;
	for (int i = 1, nid, r = n; i <= n && r > 0; ++i) {
		nid = id[r];
		pos.emplace_back (nid);
		r = nid - 1;
	}
	reverse (pos.begin (), pos.end ());
	for (int i = 1; i < pos.size (); ++i) {
		res = (res * (pos[i] - pos[i - 1] + 1)) % mod;
	}
	cout << res << endl;
}

signed main () {
	charming ();
	return 0;
}