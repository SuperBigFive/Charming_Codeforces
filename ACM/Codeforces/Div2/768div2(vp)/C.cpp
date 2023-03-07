#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5 + 5;

int t, n, k;

void init () {}

void charming () {
	init ();
	cin >> n >> k;	
	vector <pair <int, int> > ans;
	for (int i = 0; i < n / 2; ++i) {
		ans.emplace_back (make_pair (i, n - i - 1));
	}
	if (k == n - 1 && n == 4) {
		cout << -1 << endl;
		return;
	}
	else if (k == n - 1) {
		swap (ans[0].second, ans[1].first);
		swap (ans[n / 2 - 2].second, ans[n / 2 - 1].second);
	}
	else if (k < n / 2) swap (ans[0].second, ans[k].second);
	else swap (ans[0].second, ans[n - k - 1].first);
	for (auto &it : ans) {
		cout << it.first << " " << it.second << endl;
	}
}

signed main () {
	cin >> t;
	while (t--) charming ();
	return 0;
}