#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

ll t, n;
ll POW2[65], cho[65];

void get () {
	POW2[0] = 1;
	for (int i = 1; i < 63; ++i)
	POW2[i] = POW2[i - 1] * 2;
	cho[0] = 2;
	for (int i = 1; i < 62; ++i)
	cho[i] = cho[i - 1] + POW2[i + 1];
}

void init () {}

void solve (ll num, vector <int> &ans) {
	if (num == 0) return;
	for (int i = 61; i >= 0; --i) {
		if (num >= cho[i]) {
			for (int j = 1; j <= i; ++j)
			ans.emplace_back (0);
			ans.emplace_back (1);
			solve (num - cho[i], ans);
			break;
		}
	}
}
void charming () {
	init ();
	cin >> n;
	if (n & 1) return void (cout << -1 << endl);
	vector <int> ans (1, 1);
	solve (n - 2, ans);
	cout << ans.size () << endl;
	for (int i = 0; i < ans.size (); ++i)
	cout << ans[i] << " \n"[i == ans.size () - 1];
}

signed main () {
	get ();
	cin >> t;
	while (t--) charming ();
	return 0;
}